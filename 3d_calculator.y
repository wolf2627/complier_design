%{
#include<stdio.h>
%}
%token TA TD
%left '+' '-'
%left '*' '/'
%%
list:expr '\n' {printf("Accepted %d\n",$1);}
|id '=' expr '\n' {printf("Accepted %d\n",$3);}
|
;
expr:'('expr')' {$$=$2;}
|expr '+' expr {$$=$1+$3;}
|expr '-' expr {$$=$1-$3;}
|expr '*' expr {$$=$1*$3;}
|expr '/' expr {$$=$1/$3;}
|num
|id
;
num: TD {$$=$$;}
| num TD {$$=10*$1+$2;}
;
id:TA s;
s:s TA|s TD
|
;
%%
int main() {
    yyparse();
    return 0;
}
int yylex() {
    int c;
    extern int yylval;
    c=getchar();
    if(isalpha(c)) {
        yylval=c-'a';
        return (TA);
    }
    else if(isdigit(c)) {
        yylval=c-'0';
        return (TD);
    }
    else return c;
}
void yyerror() {
    printf("Not a valid arithmetic expr");
}
int yywrap() {
    return 1;
}
