%{
#include <stdio.h>
int line_count = 0;
FILE *yyin;
%}
%%
\n { line_count++; }
.;
%%
int main(int argc, char **argv) {
// Open the specified file
FILE *file = fopen("Demo.txt", "r");
if (!file) {
perror("Error opening file");
return 1;
}
yyin = file;
yylex();
fclose(file);
printf("\nNumber of lines: %d\n", line_count);
return 0;
}
int yywrap() {
return 1;
}