%{
#include <stdio.h>
%}

%%
[A-Z]+          { /* Matches uppercase letters, do nothing to remove them */ }
[ \t\n]+        { /* Matches whitespace, do nothing to remove it */ }
.               { printf("%s", yytext); } /* Matches any single character and prints it */
%%

int main(int argc, char **argv) {
    FILE *file = fopen("example.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    printf("\n");
    return 0;
}

int yywrap() {
    return 1;
}
