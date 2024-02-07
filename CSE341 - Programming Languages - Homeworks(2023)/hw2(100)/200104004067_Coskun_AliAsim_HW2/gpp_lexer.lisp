(defun is-keyword (token)
;;   "Check if the token is a keyword."
  (let ((keyword-list '("and" "or" "not" 
                        "equal" "less" "nil" 
                        "list" "append" "concat" 
                        "set" "def" "for" 
                        "if" "exit" "load" 
                        "display" "true" "false")))
    (if (member token keyword-list :test #'string-equal) ;;(case insensitive)
        t
        nil)))

;; Example usage:
;; (print (is-keyword "and"))   ; "should return "T".
;; (print (is-keyword ""))      ; should return "NIL".
;; (print (is-keyword "AND"))   ; "should return "T". (case insensitive)
;; (print (is-keyword "foo"))   ; should return "NIL".


(defun is-operator (token)
;;   "Check if the token is an operator."
  (let ((operator-list '("+" 
                         "-" 
                         "/" 
                         "*" 
                         "(" 
                         ")" 
                         ",")))
    (if (member token operator-list :test #'string-equal)
        t
        nil)))

;; Example usage:
;; (print (is-operator "+"))    ; should return "T".
;; (print (is-operator "("))    ; should return "T".
;; (print (is-operator "Foo"))  ; should return "NIL".

(defun is-comment (line)
  ;;    "Check if the line is a comment (starts with ';;')."
  (and (stringp line)
       (>= (length line) 2) ; Satır en az 2 karakter içermelidir.
       (string= ";;" (subseq line 0 2))))

;; Example usage:
;; (print (is-comment ";; This is a comment")) ; T (comment)
;; (print (is-comment ";; Another comment"))   ; T (comment)
;; (print (is-comment "Regular text"))          ; NIL (not comment)
;; (print (is-comment ""))                     ; NIL (not comment, boş satır)


(defun is-literal (token)
  ;;    "Check if the token is a literal (e.g., 123b12)."
  (if (and (stringp token)
           (>= (length token) 3)
           (digit-char-p (aref token 0))    ; is the first character number?
           (digit-char-p (aref token (1- (length token))))  ; is the last character number?
           (= (count #\b token) 1)  ; is there only one #\b?
           (= (count-if-not #'digit-char-p token) 1) ; at most one letter
           )
      t
      nil))

;; Example usage:
;; (print (is-literal "123b12"))      ;  should return "T".
;; (print (is-literal "1b2"))         ;  should return "T".
;; (print (is-literal "2342432b4"))   ;  should return "T".
;; (print (is-literal "456b"))        ;  should return "NIL".
;; (print (is-literal "124324bb5"))   ;  should return "NIL".
;; (print (is-literal "124324qb5"))   ;  should return "NIL".
;; (print (is-literal "124324q5"))    ;  should return "NIL".
;; (print (is-literal "abc1"))        ;  should return "NIL".
;; (print (is-literal "123"))         ;  should return "NIL".



(defun is-identifier (token)
  ;; "Check if the token is an identifier."
  (if (and (stringp token)  ; "token" bir karakter dizisi olmalı
           (> (length token) 0) ; Uzunluğu en az 1 olmalı (boş olmamalı)
           (alpha-char-p (char token 0))  ; İlk karakter bir harf olmalı
               
          ;;  (every #'alphanumericp token)) ; Tüm karakterler alfanumerik (harf ya da rakam) olmalıdır.
          (every #'(lambda (char) (or (alphanumericp char) (char= char #\_))) token)) ; Tüm karakterler ya bir harf ya da bir rakam ya da bir alt çizgi (_) olmalıdır.
      t
      nil))


;; Test case for identifiers:
;; (defun test-is-identifier ()
;;   "Test the is-identifier function."
;;   (let ((test-cases '("variable123" "a" "" "123variable" "var*iable" "Variable123" "example_function")))
;;     (dolist (token test-cases)
;;       (if (is-identifier token)
;;           (format t "Token is an identifier: ~A~%" token)
;;           (format t "Token is not an identifier: ~A~%" token)))))
;; (test-is-identifier)



(defun split-input (input)
  "Tokenize the input string character by character while recognizing complete literals."
  (let ((tokens '())   ; List to store tokens
        (token "")     ; Current token being formed
        (in-token nil) ; Flag to indicate if we are inside a token
        (double-semi-colon-flag nil) ; Flag for specifying consecutive semicolon characters (;;)
        (temp t)  ; A temp variable to help the is-comment function
        ;; (newlines t)) ; A temp variable to avoid the newline character
        )
    (loop for char across input
          ;; for temp = t
          ;; for newlines = t
          do

          ;; (if (and (char= char #\Newline) (char= char #\Return) (char= char #\Space))
          ;;   (progn (setf newlines nil)))

          (if (and (char= char #\;) double-semi-colon-flag)
              (progn
                (push ";;" tokens)
                (setf double-semi-colon-flag nil) ; Reset the flag for two consecutive semicolon characters
                (setf temp nil)
          ))

          (if (and (char= char #\;) temp )
              (progn (setf double-semi-colon-flag t)))  ; Set the flag for two consecutive semicolon characters
          
          (if (alphanumericp char)
              (progn
                (setf token (concatenate 'string token (string char))
                      in-token t))
              (if in-token
                  (progn
                    (push token tokens)
                    (setf token ""
                          in-token nil))))
        
          (if (and (not (alphanumericp char)) (not (char= char #\space)) temp (not double-semi-colon-flag) )
                (push char tokens))
          ;; (print tokens)
          (setf temp t)
      )

    (when in-token
      (push token tokens))  ;;the last token
    (nreverse tokens)))



(defun tokenize-input (input)
  "Tokenize the user input and categorize each token."

  (let* ((tokens (split-input input)) ; Split input into tokens
         (categorized-tokens '())) ; List to store categorized tokens

    (loop for token in tokens
          for flag = nil ; Initialize the flag for each token
          do
          (cond
            ((is-keyword token)
              (let ((kw-symbol (cond
                                ((string= token "and") "KW_AND")
                                ((string= token "or") "KW_OR")
                                ((string= token "not") "KW_NOT")
                                ((string= token "equal") "KW_EQUAL")
                                ((string= token "less") "KW_LESS")
                                ((string= token "nil") "KW_NIL")
                                ((string= token "list") "KW_LIST")
                                ((string= token "append") "KW_APPEND")
                                ((string= token "concat") "KW_CONCAT")
                                ((string= token "set") "KW_SET")
                                ((string= token "def") "KW_DEF")
                                ((string= token "for") "KW_FOR")
                                ((string= token "if") "KW_IF")
                                ((string= token "exit") "KW_EXIT")
                                ((string= token "load") "KW_LOAD")
                                ((string= token "display") "KW_DISPLAY")
                                ((string= token "true") "KW_TRUE")
                                ((string= token "false") "KW_FALSE")
                                (t (string-upcase token)))))
                (format t "~A~%" kw-symbol)
                (setf flag t)))
            ((is-operator token)
              (let ((op-symbol (cond
                                ((string= token "+") "OP_PLUS")
                                ((string= token "-") "OP_MINUS")
                                ((string= token "/") "OP_DIV")
                                ((string= token "*") "OP_MULT")
                                ((string= token "(") "OP_OP")
                                ((string= token ")") "OP_CP")
                                ((string= token ",") "OP_COMM")
                                (t (string-upcase token)))))
                (format t "~A~%" op-symbol)
                (setf flag t)))
                ;; (push (format t "~A~%" op-symbol) categorized-tokens))) ;; also adds to the list called categorized-tokens

            ((is-comment token) (format t "COMMENT~%")
                                (setf flag t))
            ((is-literal token) (format t "VALUEF~%")
                                (setf flag t))
            ((is-identifier token) (format t "IDENTIFIER~%")
                                (setf flag t))

            (t
                (if (or (member token '(#\Newline #\Return #\Space)))
                    ()
                    (format t "SYNTAX ERROR ~A cannot be tokenized.~%" token))
                (setf flag t)))
  
          (unless flag
            (if (or (member token '(#\Newline #\Return #\Space)))
                    ()
                    (format t "SYNTAX ERROR ~A cannot be tokenized.~%" token))
            (push "SYNTAX ERROR" categorized-tokens)))
            
            ;; (t (push token categorized-tokens)))) ; Handle unrecognized tokens
    (nreverse categorized-tokens))) ; Reverse the list for correct order



;; Example usage without gppinterpreter:
;; (let ((input "(list 1b1 2b1 123b12) nil and + ;; aaa deneme id+id load b and 123 1b2 or b2c 7 def(set x) sonunda def"))
;; (let ((input ";; helloworld.g++
;; (def sumup (x) 
;;  (if (equal x 0) 
;;  1 
;;  (+ x (sumup (- x 1)))
;;  )
;;  )"))
;;   (format t "~{~a~^ ~}" (tokenize-input input)))

(defun gppinterpreter(&optional input-file)
  "G++ Language Lexer Interpreter."
  (if input-file
      (with-open-file (file input-file :direction :input)
        (let ((input (read-line file nil)))
          (format t "Input: ~a~%" input)
          (format t "Output. ~{~a~^ ~}~%" (tokenize-input input))))
      (progn
        (format t "Enter your G++ expression or statement (or type :quit to exit):~%")
        (loop
          (format t "> ")
          (finish-output)
          (let ((input (read-line)))
            (when (string= input ":quit")
              (format t "Exiting G++ interpreter.~%")
              (return))
            (format t "Output! ~{~a~^ ~}~%" (tokenize-input input))
            (terpri))))))


;; Example usage:
;; If you have an input file:
;; (gppinterpreter "test1")

;; If you want to input manually:
;; (gppinterpreter)
