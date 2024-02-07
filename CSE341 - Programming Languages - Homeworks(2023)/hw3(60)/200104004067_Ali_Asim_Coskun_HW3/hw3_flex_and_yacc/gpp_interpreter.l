%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_FUNCTIONS 100
#define MAX_NAME_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ARG_COUNT 10

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

void reduce_fraction(Fraction *f);
Fraction createFraction(int numerator, int denominator);
Fraction addFractions(Fraction a, Fraction b);
Fraction subtractFractions(Fraction a, Fraction b);
Fraction multiplyFractions(Fraction a, Fraction b);
Fraction divideFractions(Fraction a, Fraction b);
void printFraction(Fraction f);
int extract_arg_names(char* arg_list, char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH]);
void serialize_exp(Fraction exp, char* output, size_t output_size);
int exp_to_string(Fraction exp, char* output, size_t output_size);
int check_arg_body_match(char arg_names[MAX_ARG_COUNT][MAX_NAME_LENGTH], int arg_count, char* body);
int call_function(char* name, char args[MAX_ARG_COUNT][MAX_NAME_LENGTH], int arg_count);
#include "y.tab.h"
%}

%option noyywrap

%%

"and"         { return KW_AND; } /* Keywords */
"or"          { return KW_OR; }
"not"         { return KW_NOT; }
"equal"       { return KW_EQUAL; }
"less"        { return KW_LESS; }
"nil"         { return KW_NIL; }
"list"        { return KW_LIST; }
"append"      { return KW_APPEND; }
"concat"      { return KW_CONCAT; }
"set"         { return KW_SET; }
"def"         { return KW_DEF; }
"for"         { return KW_FOR; }
"if"          { return KW_IF; }
"exit"        { return KW_EXIT; }
"load"        { return KW_LOAD; }
"display"     { return KW_DISPLAY; }
"true"        { return KW_TRUE; }
"false"       { return KW_FALSE; }

"+"           { return OP_PLUS; } /* Operators */
"-"           { return OP_MINUS; }
"/"           { return OP_DIV; }
"*"           { return OP_MULT; }
"("           { return OP_OP; }
")"           { return OP_CP; }
","           { return OP_COMMA; }

";;".*        { /* Ignore comments */ } /* Comments */

[0-9]+b[0-9]+ { /* Fraction Literals */
    int numerator, denominator;
    sscanf(yytext, "%db%d", &numerator, &denominator);
    yylval.fraction.numerator = numerator;
    yylval.fraction.denominator = denominator;
    return VALUEF;
}

[a-zA-Z][a-zA-Z0-9]* { /* Identifiers */
    // printf("Identifier token found: %s\n", yytext);
    yylval.str = strdup(yytext); 
    return IDENTIFIER; 
}
[ \t\n]+          { /* ignore whitespace */ }
.                 { /* catch all for other characters */ }

%%
