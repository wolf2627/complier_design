%{
int t='A'-1;
%}
%token TA TD
%left '+' '-'
%left '*' '/'
%%
list:list expr '\n'
|
;
expr:TA {}
|TD {}
|expr '+' expr {t++; printf("\n %c%c%c%c",t,$1,$3,'+'); $$=t;}
|expr '-' expr {t++; printf("\n %c%c%c%c",t,$1,$3,'-'); $$=t;}
|expr '*' expr {t++; printf("\n %c%c%c%c",t,$1,$3,'*'); $$=t;}
|'('expr')' {$$=t;}
|expr '=' expr {t++; printf("\n %c%c%c%c",t,$1,$3,'='); $$=t;}
%%
int main(){
    yyparse();
    return 0;
}
int yylex(){
    int c;
    extern int yylval;
    c=getchar();
    if(isalpha(c)){
        yylval=c;
        return TA;
    }
    if(isdigit(c)){
        yylval=c-'0';
        return TD;
    }
    else return c;
}
int yywrap(){
    return 1;
}
void yyerror(){
  printf("error");
}
