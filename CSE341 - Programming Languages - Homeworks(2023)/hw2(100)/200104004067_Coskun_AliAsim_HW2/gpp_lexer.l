%{
#include <stdio.h>
%}

%option noyywrap

%%

"and" {
    printf("KW_AND\n");  // Print "KW_AND" when "and" is encountered.
}

"or" {
    printf("KW_OR\n");  // Print "KW_OR" when "or" is encountered.
}

"not" {
    printf("KW_NOT\n");  // Print "KW_NOT" when "not" is encountered.
}

"equal" {
    printf("KW_EQUAL\n");  // Print "KW_EQUAL" when "equal" is encountered.
}

"less" {
    printf("KW_LESS\n");  // Print "KW_LESS" when "less" is encountered.
}

"nil" {
    printf("KW_NIL\n");  // Print "KW_NIL" when "nil" is encountered.
}

"list" {
    printf("KW_LIST\n");  // Print "KW_LIST" when "list" is encountered.
}

"append" {
    printf("KW_APPEND\n");  // Print "KW_APPEND" when "append" is encountered.
}

"concat" {
    printf("KW_CONCAT\n");  // Print "KW_CONCAT" when "concat" is encountered.
}

"set" {
    printf("KW_SET\n");  // Print "KW_SET" when "set" is encountered.
}

"def" {
    printf("KW_DEF\n");  // Print "KW_DEF" when "def" is encountered.
}

"for" {
    printf("KW_FOR\n");  // Print "KW_FOR" when "for" is encountered.
}

"if" {
    printf("KW_IF\n");  // Print "KW_IF" when "if" is encountered.
}

"exit" {
    printf("KW_EXIT\n");  // Print "KW_EXIT" when "exit" is encountered.
}

"load" {
    printf("KW_LOAD\n");  // Print "KW_LOAD" when "load" is encountered.
}

"display" {
    printf("KW_DISPLAY\n");  // Print "KW_DISPLAY" when "display" is encountered.
}

"true" {
    printf("KW_TRUE\n");  // Print "KW_TRUE" when "true" is encountered.
}

"false" {
    printf("KW_FALSE\n");  // Print "KW_FALSE" when "false" is encountered.
}

[+] {
    printf("OP_PLUS\n");  // Print "OP_PLUS" when "+" is encountered.
}
[-] {
    printf("OP_MINUS\n");  // Print "OP_MINUS" when "-" is encountered.
}
[*] {
    printf("OP_MULT\n");  // Print "OP_MULT" when "*" is encountered.
}
[/] {
    printf("OP_DIV\n");  // Print "OP_DIV" when "/" is encountered.
}
[(] {
    printf("OP_OP\n");  // Print "OP_OP" when "(" is encountered.
}
[)] {
    printf("OP_CP\n");  // Print "OP_CP" when ")" is encountered.
}
[,] {
    printf("OP_COMMA\n");  // Print "OP_COMMA" when "," is encountered.
}

;;.* {
    printf("COMMENT\n");  // Print "COMMENT" for any text after ";;" as a comment.
}

[0-9]+b[0-9]+ {
    printf("VALUEF\n");  // Print "VALUEF" for values like "12b34".
}

[a-zA-Z][a-zA-Z0-9_]* {
    printf("IDENTIFIER\n");  // Print "IDENTIFIER" for valid identifiers.
}

[ \t\n] /* Ignore whitespace and new lines */

. {
    printf("SYNTAX_ERROR %s\n", yytext);  // Print "SYNTAX_ERROR" for any other character.
}

%%

int main() {
    yylex();
    return 0;
}
