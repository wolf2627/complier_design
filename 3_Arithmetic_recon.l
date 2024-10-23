%{
#include<stdio.h>
%}
%token TA TD
%left '+' '-'
%left '*' '/'
%%
list:expr '\n' {printf("Accepted");}
|id '=' expr '\n' {printf("Accepted");}
|
;
expr:'('expr')'
|expr '+' expr
|expr '-' expr
|expr '*' expr
|expr '/' expr
|num
|id
;
num: TD
| num TD
;
id:TA s
;
%%
int main() { return(yyparse()); }
int yylex() {
    char c;
    c=getchar();
    if(isalpha(c)) return(TA);
    if(isdigit(c)) return(TD);
    return c;
}
void yyerror(char *s) { printf("%s",s); }
