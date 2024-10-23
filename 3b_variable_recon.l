%{
#include<stdio.h>
%}
%token TA TD
%%
list:TA s '\n' {printf("\n Accepted\n");}
;
s:s TA|s TD
|
;
%%
int main() {
    return(yyparse());
}
int yylex() {
    char c;
    c=getchar();
    if(isalpha(c)) return(TA);
    if(isdigit(c)) return(TD);
    return c;
}
void yyerror(char *s) {
    printf("%s",s);
}
