%{
#include <stdio.h>
#include <stdlib.h>
%}
%%
[+-]?[0-9]+(\.[0-9]*)?([eE][+-]?[0-9]+)? {
if (yytext[0] == '-' || yytext[0] == '+') {
printf("\n Number is %s...\n", yytext[0] == '-' ? "negative" : "positive");
} else if (strchr(yytext, '.') != NULL) {
if (strchr(yytext, 'e') != NULL || strchr(yytext, 'E') != NULL) {
printf("\n Number is exponential...\n");
} else {
printf("\n Number is real...\n");
}
} else {
printf("\n Number is integer...\n");
}
}
[ \t\n]+ /* Ignore whitespace */
. { /* Ignore any other characters */ }
%%
int yywrap() {
return 1;
}
int main() {
printf("Enter numbers to classify:\n");
yylex();
return 0;
}