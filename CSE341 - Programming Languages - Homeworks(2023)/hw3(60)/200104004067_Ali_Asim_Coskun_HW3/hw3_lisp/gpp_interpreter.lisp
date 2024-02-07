(ql:quickload "split-sequence")
(use-package :split-sequence)

(defvar *function-definitions* (make-hash-table :test 'equal))

(defun define-function (name params body)
  "Defines function and stores it in *function-definitions*."
  (setf (gethash (string-upcase name) *function-definitions*) (list params body))
;;   (format t "Function defined: ~A~%" name) ; Print message when a function is defined
  ) 

(defun parse-function-definition (tokens)
  "Parses token list to define a function."
  (let ((name (second tokens))
        (params (list (third tokens) (fourth tokens)))
        (body (subseq tokens 4)))
    (define-function name params body)
    `(function-defined ,name)))

;; (print (parse-function-definition '(def sum x y (+ x y))))
;; expected output: (function-defined sum)

;; Temporary apply-function definition
(defun apply-function (function-definition arguments)
  (error "apply-function is not yet implemented")
  function-definition
  arguments)

(defun evaluate-expression (expr)
  "Evaluates an expression tree."
  (if (and (listp expr) (not (null expr)))
      (let* ((inner-expr (if (listp (first expr)) (first expr) expr))
             (operator (if (and (listp inner-expr) (gethash (string-upcase (string (first inner-expr))) *function-definitions*))
                           :FUNCTION-CALL
                           (intern (string-upcase (string (first inner-expr))) :keyword)))
             (operands (rest inner-expr)))
        (case operator
          ((:+) (if (= (length operands) 2)
                     (reduce #'+ (mapcar #'evaluate-expression operands))
                     (progn (format t "Syntax error: + operator expects exactly two operands~%") nil)))
          ((:-) (if (= (length operands) 2)
                     (reduce #'- (mapcar #'evaluate-expression operands))
                     (progn (format t "Syntax error: - operator expects exactly two operands~%") nil)))
          ((:*) (if (= (length operands) 2)
                     (reduce #'* (mapcar #'evaluate-expression operands))
                     (progn (format t "Syntax error: * operator expects exactly two operands~%") nil)))
          ((:/) (if (= (length operands) 2)
                     (reduce #'/ (mapcar #'evaluate-expression operands))
                     (progn (format t "Syntax error: / operator expects exactly two operands~%") nil)))
          ((:IF) (let ((condition (evaluate-expression (first operands)))
                       (true-branch (second operands))
                       (false-branch (third operands)))
                   (if (not (zerop condition))
                       (evaluate-expression true-branch)
                       (evaluate-expression false-branch))))
          (:DEF (parse-function-definition inner-expr))
          (:FUNCTION-CALL (let* ((function-name (string-upcase (string (first inner-expr))))
                       (arguments (mapcar #'evaluate-expression (rest inner-expr)))
                       (function-definition (gethash function-name *function-definitions*)))
                  (if function-definition
                      (apply-function function-definition arguments)
                      (error "Function not defined: ~A" function-name))))
          (:EXIT (sb-ext:exit))
          (t (error "Unknown operator"))))
      expr))

(defun substitute-bindings (expression bindings)
  "Substitutes variables in an expression with corresponding values from bindings."
  (if (listp expression)
      (mapcar (lambda (expr) (substitute-bindings expr bindings)) expression)
      (or (cdr (assoc expression bindings :test #'equal)) expression)))

(defun apply-function (function-definition arguments)
  "Applies defined function to given arguments."
  (let ((params (first function-definition))
        (body (second function-definition)))
    (let ((bindings (pairlis params arguments)))
      (evaluate-expression (substitute-bindings body bindings)))))

(defun tokenize (input)
  "Tokenizes the input string."
  (let ((tokens '())
        (current-token "")
        (i 0)
        (len (length input)))
    (loop while (< i len)
          do (let ((char (char input i)))
               (cond
                ((member char '(#\+ #\- #\* #\/)) 
                 (when (> (length current-token) 0)
                   (push (string-trim " " current-token) tokens)
                   (setf current-token ""))
                 (push (string char) tokens))
                ((member char '(#\( #\))) 
                 (when (> (length current-token) 0)
                   (push (string-trim " " current-token) tokens)
                   (setf current-token ""))
                 (push (string char) tokens))
                ((char= char #\Space) 
                 (when (> (length current-token) 0)
                   (push (string-trim " " current-token) tokens)
                   (setf current-token "")))
                (t (setf current-token (concatenate 'string current-token (string char)))))
               (incf i)))
    (when (> (length current-token) 0)
      (push (string-trim " " current-token) tokens))
    (nreverse tokens)))

(defun parse-fraction (str)
  "Parses a fraction string into a numeric value."
  (let ((parts (split-sequence #\b str)))
    (let ((numerator (parse-integer (first parts)))
          (denominator (parse-integer (second parts))))
      (/ numerator denominator))))

(defun parse-token (token)
  "Converts a token into its corresponding value or operator."
  (cond
   ((member token '("+" "-" "*" "/" "if")) token)
   ((and (> (length token) 2) 
         (find #\b token) 
         (not (char= (char token 0) #\b)) 
         (not (char= (char token (1- (length token))) #\b)))
    (parse-fraction token))
   (t token)))

(defun parse (tokens)
  "Parses the tokens into an expression tree."
  (let ((stack (list nil)))
    (dolist (token tokens (first stack))
      (cond
       ((string= token "(") (push nil stack))
       ((string= token ")") 
        (let ((expr (nreverse (pop stack))))
          (unless (null stack)
            (push expr (first stack)))))
       (t (push (parse-token token) (first stack)))))))

(defun gpp-interpreter (input)
  "Processes and evaluates the given input."
  (let ((parsed-expr (parse (tokenize input))))
    (let ((result (evaluate-expression parsed-expr)))
      (if result
          (format t "Result: ~A~%" result)) ; Print the result of each expression only if it's not nil
      result)))
      
(defun process-file (filename)
  "Reads a file and processes each line with gpp-interpreter."
  (with-open-file (stream filename)
    (loop for line = (read-line stream nil 'eof)
          until (eq line 'eof)
          do (let ((trimmed-line (string-trim '(#\Space #\Newline #\Return #\Tab) line)))
               (format t "~%Processing line: ~A~%" trimmed-line)
               (gpp-interpreter trimmed-line)))))

;; either put line 156 in the comment line or put the test cases in the comment line.
(process-file "test.g++")

;; ;; Test Case 0: Function Definition
;; (gpp-interpreter "(def sum x y (+ x y))") ; Expected output: Function-defined: sum
;; (gpp-interpreter "(sum 4b2 6b1)") ; Expected output: 8

;; ;; Test Case 1: Basic Arithmetic Operations
;; (gpp-interpreter "(+ 3b1 4b1)")  ; Expected output: 7
;; (gpp-interpreter "(- 5b1 2b1)")  ; Expected output: 3
;; (gpp-interpreter "(* 3b1 4b1)")  ; Expected output: 12
;; (gpp-interpreter "(/ 8b1 4b1)")  ; Expected output: 2

;; ;; Test Case 2: Syntax Error
;; (gpp-interpreter "(* 4f1 6f1 8f1)")  ; Expected output: Syntax error!

;; ;; Test Case 3: Nested Arithmetic Operations
;; (gpp-interpreter "(+ 1b1 (* 2b1 3b1))")  ; Expected output: 7

;; ;; Test Case 4: Conditional Statement (If)
;; (gpp-interpreter "(if 1b1 5b1 10b1)")  ; Expected output: 5 (True condition)
;; (gpp-interpreter "(if 0b1 5b1 10b1)")  ; Expected output: 10 (False condition)

;; ;; Test Case 5: Function Definitions and Calls
;; (gpp-interpreter "(def sum x y (+ x y))")  ; Expected output: Function-defined: sum
;; (gpp-interpreter "(sum 4b1 6b1)")         ; Expected output: 10
;; (gpp-interpreter "(def mul x y (* x y))") ; Expected output: Function-defined: mul
;; (gpp-interpreter "(mul 3b1 4b1)")         ; Expected output: 12

;; ;; Test Case 6: Nested Function Calls
;; (gpp-interpreter "(sum 3b1 (mul 2b1 3b1))")  ; Expected output: 9

;; ;; Test Case 7: Using Functions in Conditional Statements
;; (gpp-interpreter "(if 0b2 (mul 2b1 3b1) (mul 4b1 5b1))")  ; Expected output: 20
