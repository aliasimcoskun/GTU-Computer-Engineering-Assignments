%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_FUNCTIONS 100
#define MAX_NAME_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ARG_COUNT 10
#define MAX_WORD_COUNT 100
#define MAX_WORD_SIZE 100

void yyerror(const char *s) {
    fprintf(stderr, "yyerror: Error: %s\n", s);
}
int yylex(void);

typedef struct Fraction {
    int numerator;
    int denominator;
} Fraction;

typedef struct {
    char name[MAX_NAME_LENGTH]; // Function name
    char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH]; // Argument names
    char body[MAX_BODY_LENGTH]; // Function body as a string
    int arg_count; // Number of arguments
} Function;

Function function_table[MAX_FUNCTIONS];
int function_count = 0;

void reduce_fraction(Fraction *f);
Fraction createFraction(int numerator, int denominator);
Fraction addFractions(Fraction a, Fraction b);
Fraction subtractFractions(Fraction a, Fraction b);
Fraction multiplyFractions(Fraction a, Fraction b);
Fraction divideFractions(Fraction a, Fraction b);
void printFraction(Fraction f);
int extract_arg_names(char* arg_list, char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH]);
int serialize_exp(Fraction exp, char* output, size_t output_size);
int exp_to_string(Fraction exp, char* output, size_t output_size);
int check_arg_body_match(char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH], int arg_count, char* body);
int define_function(char* name, char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH], int arg_count, char* body) {
    strncpy(function_table[function_count].name, name, MAX_NAME_LENGTH);
    function_table[function_count].arg_count = arg_count;
    for (int i = 0; i < arg_count; i++) {
        strncpy(function_table[function_count].arg_names[i], arg_names[i], MAX_NAME_LENGTH);
    }
    strncpy(function_table[function_count].body, body, MAX_NAME_LENGTH);
    function_count++;
    return 0;
}

char get_operator(char* str) {
    // Define the operators
    char operators[] = "+-*/";

    // Search for the operators in the string
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; operators[j] != '\0'; j++) {
            if (str[i] == operators[j]) {
                return operators[j];
            }
        }
    }

    // If no operator is found, return a null character
    return '\0';
}

Fraction string_to_fraction(char* str) {
    Fraction fraction;
    char* slash = strchr(str, '/');
    if (slash != NULL) {
        *slash = '\0';
        fraction.numerator = atoi(str);
        fraction.denominator = atoi(slash + 1);
    } else {
        fraction.numerator = atoi(str);
        fraction.denominator = 1;
    }
    return fraction;
}

int convert_to_fractions(char* value_list, Fraction* fractions) {
    int count = 0;
    char* token = strtok(value_list, " ");
    while (token != NULL) {
        fractions[count] = string_to_fraction(token);  
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

Fraction call_function(char* name, Fraction* args, int arg_count) {

    Fraction result; // Initialize result

    for (int i = 0; i < function_count; i++) {
        if (strcmp(function_table[i].name, name) == 0) {
            char* body = function_table[i].body;
            char operator = get_operator(body);  
            result = args[0];  // Start with the first argument
            for (int j = 1; j < arg_count; j++) {  // Apply the operator with the rest of the arguments
                switch (operator) {
                    case '+':
                        result = addFractions(result, args[j]);
                        break;
                    case '-':
                        result = subtractFractions(result, args[j]);
                        break;
                    case '*':
                        result = multiplyFractions(result, args[j]);
                        break;
                    case '/':
                        result = divideFractions(result, args[j]);
                        break;
                    default:
                        printf("Unknown operator: %c\n", operator);
                        return result;
                }
            }
            printf("%s: %d/%d\n", name, result.numerator, result.denominator);
            return result;
        }
    }

    printf("Function %s not found\n", name);
    result.numerator = -1;
    result.denominator = -1;
    return result;
}

Fraction evaluate_if_statement(Fraction condition, Fraction true_expression, Fraction false_expression) {
    if (condition.numerator != 0) {
        // Condition is true, return the true expression
        return true_expression;
    } else {
        // Condition is false, return the false expression
        return false_expression;
    }
}

char* fraction_to_string(Fraction fraction) {
    // Allocate memory for the string
    char* str = malloc(64);  // Adjust the size as needed

    // Check if the denominator is 1
    if (fraction.denominator == 1) {
        // Just print the numerator
        sprintf(str, "%d", fraction.numerator);
    } else {
        // Print the numerator and the denominator
        sprintf(str, "%d/%d", fraction.numerator, fraction.denominator);
    }

    return str;
}

%}

%union {
    Fraction fraction; /* Fraction type for fraction values */
    char* str;        /* For string values like identifiers */
}

%token <fraction> VALUEF
%token <str> IDENTIFIER
%token KW_AND KW_OR KW_NOT KW_EQUAL KW_LESS KW_NIL KW_LIST KW_APPEND KW_CONCAT KW_SET KW_DEF KW_FOR KW_IF KW_EXIT KW_LOAD KW_DISPLAY KW_TRUE KW_FALSE OP_PLUS OP_MINUS OP_DIV OP_MULT OP_OP OP_CP OP_COMMA

%type <fraction> exp 
%type <fraction> function_call
%type <str> function
%type <str> arg_list
%type <str> body
%type <str> value_list
%type <fraction> if_statement

%%
start
    : start exp
    | start function
    | start if_statement
    | exp
    | function
    | if_statement
    ;

exp
    : VALUEF { $$ = $1; }
    | OP_OP OP_PLUS exp exp OP_CP { $$ = addFractions($3, $4); printFraction($$);}
    | OP_OP OP_MINUS exp exp OP_CP { $$ = subtractFractions($3, $4); printFraction($$);}
    | OP_OP OP_MULT exp exp OP_CP { $$ = multiplyFractions($3, $4); printFraction($$);}
    | OP_OP OP_DIV exp exp OP_CP { $$ = divideFractions($3, $4); printFraction($$);}
    | OP_OP OP_PLUS exp exp exp OP_CP { printf("Syntax error: + operator expects exactly two operands\n"); }
    | OP_OP OP_MINUS exp exp exp OP_CP { printf("Syntax error: - operator expects exactly two operands\n"); }
    | OP_OP OP_MULT exp exp exp OP_CP { printf("Syntax error: * operator expects exactly two operands\n"); }
    | OP_OP OP_DIV exp exp exp OP_CP { printf("Syntax error: / operator expects exactly two operands\n"); }
    | function_call
    | IDENTIFIER { 
        // printf("EXP: Found identifier: %s\n", $1);
    }
    | OP_OP KW_EXIT OP_CP {exit(0);}
    ;

function
    : OP_OP KW_DEF IDENTIFIER arg_list body OP_CP {
        char* temp_body = strdup($5);
        strncpy(function_table[function_count].name, $3, MAX_NAME_LENGTH);
        function_table[function_count].arg_count = extract_arg_names($4, function_table[function_count].arg_names);
        // Check that all identifiers in the body are present in the arguments
        if (check_arg_body_match(function_table[function_count].arg_names, function_table[function_count].arg_count, $5) != 0) {
            printf("Argument names do not match identifiers in function body.\n");
            return 0; // Skip adding this function due to error
        }
        strncpy(function_table[function_count].body, temp_body, MAX_BODY_LENGTH);
        function_count++;
        printf("Function %s defined\n", $3);
        free(temp_body);
      }
    ;

body
    : OP_OP OP_PLUS body OP_CP {
        char* temp = malloc(strlen($3) + 4 + 1); // 4 for "(+ )" and 1 for null terminator
        sprintf(temp, "(+ %s)", $3);
        $$ = temp;
    }
    | OP_OP OP_MINUS body OP_CP {
        char* temp = malloc(strlen($3) + 4 + 1); // 4 for "(- )" and 1 for null terminator
        sprintf(temp, "(- %s)", $3);
        $$ = temp;
    }
    | OP_OP OP_MULT body OP_CP {
        char* temp = malloc(strlen($3) + 4 + 1); // 4 for "(* )" and 1 for null terminator
        sprintf(temp, "(* %s)", $3);
        $$ = temp;
    }
    | OP_OP OP_DIV body OP_CP {
        char* temp = malloc(strlen($3) + 4 + 1); // 4 for "(/ )" and 1 for null terminator
        sprintf(temp, "(/ %s)", $3);
        $$ = temp;
    }
    | arg_list {
        $$ = strdup($1);
    }
    ;

value_list
    : value_list VALUEF {
        char *temp = malloc(strlen($1) + 1 + 20 + 1);  // Allocate space for concatenated string
        if (temp) {
            sprintf(temp, "%s %d/%d", $1, $2.numerator, $2.denominator);  // Concatenate the strings
            free($1);  // Free the old string
            $$ = temp;  // Set the concatenated string as the new value
        }
    }
    | VALUEF {
        char *temp = malloc(20 + 1);  // Allocate space for string
        if (temp) {
            sprintf(temp, "%d/%d", $1.numerator, $1.denominator);  // Convert fraction to string
            $$ = temp;  // Set the string as the new value
        }
    }
    ;

function_call
    : OP_OP IDENTIFIER value_list OP_CP {
        // Find the function by name
        for (int i = 0; i < function_count; i++) {
            if (strcmp(function_table[i].name, $2) == 0) {
                // Convert value_list to array of Fractions
                Fraction args[MAX_ARG_COUNT];
                int arg_count = convert_to_fractions($3, args);
                // Call the function
                $$ = call_function($2, args, arg_count);
                break;
            }
        }
    }
    ;

arg_list
    : arg_list IDENTIFIER {
        char *temp = malloc(strlen($1) + 1 + strlen($2) + 1);  // Allocate space for concatenated string
        if (temp) {
            sprintf(temp, "%s %s", $1, $2);  // Concatenate the strings
            free($1);  // Free the old string
            $$ = temp;  // Set the concatenated string as the new value
        }
    }
    | IDENTIFIER {
        $$ = strdup($1);  // Duplicate the first identifier
    }
    ;

if_statement
    : OP_OP KW_IF VALUEF exp exp OP_CP {
        // Convert the condition to a Fraction
        Fraction condition = $3;
        
        // Convert the expressions to Fractions
        Fraction true_expression = $4;
        Fraction false_expression = $5;

        // Evaluate the if statement
        Fraction result = evaluate_if_statement(condition, true_expression, false_expression);
        
        // Convert the result to a string
        $$ = result;
        printf("%d/%d\n", $$.numerator, $$.denominator);
    }
    ;
%%

void reduce_fraction(Fraction *f) {
    int gcd, a = f->numerator, b = f->denominator;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    f->numerator /= gcd;
    f->denominator /= gcd;
}

Fraction createFraction(int numerator, int denominator) {
    Fraction f = {0, 0};
    f.numerator = numerator;
    f.denominator = denominator;
    reduce_fraction(&f);
    return f;
}

Fraction addFractions(Fraction a, Fraction b) {
    Fraction f = {0, 0};
    f.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;
    reduce_fraction(&f);
    return f;
}

Fraction subtractFractions(Fraction a, Fraction b) {
    Fraction f = {0, 0};
    f.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;
    reduce_fraction(&f);
    return f;
}

Fraction multiplyFractions(Fraction a, Fraction b) {
    Fraction f = {0, 0};
    f.numerator = a.numerator * b.numerator;
    f.denominator = a.denominator * b.denominator;
    reduce_fraction(&f);
    return f;
}

Fraction divideFractions(Fraction a, Fraction b) {
    Fraction f = {0, 0};
    f.numerator = a.numerator * b.denominator;
    f.denominator = a.denominator * b.numerator;
    reduce_fraction(&f);
    return f;
}

void printFraction(Fraction f){
    printf("%d/%d\n", f.numerator, f.denominator);
}

int extract_arg_names(char* arg_list, char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH]) {
    int arg_count = 0;
    char* token = strtok(arg_list, " ");
    while (token != NULL && arg_count < MAX_ARG_COUNT) {
        strncpy(arg_names[arg_count], token, MAX_NAME_LENGTH);
        arg_count++;
        token = strtok(NULL, " ");
    }
    return arg_count;
}

int serialize_exp(Fraction exp, char* output, size_t output_size) {
    int written = snprintf(output, output_size, "%d/%d", exp.numerator, exp.denominator);
    return (written > 0 && written < output_size) ? 0 : -1;
}

int exp_to_string(Fraction exp, char* output, size_t output_size) {
    int written = snprintf(output, output_size, "%d/%d", exp.numerator, exp.denominator);
    return (written > 0 && written < output_size) ? 0 : -1;
}

int check_arg_body_match(char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH], int arg_count, char* body) {
    char* body_copy = strdup(body);
    char* token = strtok(body_copy, " ()"); // added parentheses to the delimiter set
    while (token != NULL) {
        token = strtok(NULL, " ()"); // added parentheses to the delimiter set
    }
    // Reset token
    free(body_copy);
    body_copy = strdup(body);
    token = strtok(body_copy, " ()");

    while (token != NULL) {
        if (strcmp(token, "+") != 0 && strcmp(token, "-") != 0 && strcmp(token, "*") != 0 && strcmp(token, "/") != 0) {
            // token is an identifier
            int match_found = 0;
            for (int i = 0; i < arg_count; i++) {
                if (strcmp(token, arg_names[i]) == 0) {
                    match_found = 1;
                    break;
                }
            }
            if (match_found == 0) {
                // identifier in body does not match any arg name
                free(body_copy);
                return -1;
            }
        }
        else {
            // printf("check_arg_body_match: Token is an operator or parentheses: %s\n", token);
        }
        token = strtok(NULL, " ()"); // added parentheses to the delimiter set
    }
    free(body_copy);
    return 0; // all identifiers in body match arg names
}

int main() {
    int parseResult = yyparse();
    if (parseResult == 0) {
        printf("\nParsing completed successfully.\n");
    } else {
        printf("\nParsing failed.\n");
    }
    return parseResult;
}