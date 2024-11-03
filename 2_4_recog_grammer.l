%{
#include <stdio.h>
#include <stdlib.h>
int stack = 0;
int error = 0;
%}

%%
a           { stack++; }
b           { 
                if (stack > 0)
                    stack--;
                else
                    error = 1;
            }
[^ab\n]+    { error = 1; }
\n          { return 0; }
%%

int main() {
    printf("Enter a string of a's and b's: ");
    fflush(stdout);
    yylex();
    if (error || stack != 0) {
        printf("The string does NOT match the grammar a^n b^n\n");
    } else {
        printf("The string matches the grammar a^n b^n\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}
