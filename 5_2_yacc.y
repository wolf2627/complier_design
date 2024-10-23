%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%token INT FLOAT STRING ADD SUB MUL DIV EQ LPAREN RPAREN
%left ADD SUB
%left MUL DIV
%nonassoc EQ
%%
program:expr { printf("Type check passed!\n"); }
;
expr:INT { $$ = INT; }
|FLOAT { $$ = FLOAT; }
|STRING { $$ = STRING; }
|expr ADD expr { if ($1 != $3) {yyerror("Type mismatch: cannot add different types");exit(0);} else $$ = $1; }
|expr SUB expr { if ($1 != $3) {yyerror("Type mismatch: cannot subtract different types");exit(0);} else $$ = $1; }
|expr MUL expr { if ($1 != $3) {yyerror("Type mismatch: cannot multiply different types");exit(0);} else $$ = $1; }
|expr DIV expr { if ($1 != $3) {yyerror("Type mismatch: cannot divide different types");exit(0);} else $$ = $1; }
|expr EQ expr { if ($1 != $3) {yyerror("Type mismatch: cannot compare different types");exit(0);} else $$ = $1; }
|LPAREN expr RPAREN { $$ = $2; }
;
%%
int main() {
    yyparse();
    return 0;
}
int yyerror(char* s) {
    printf("Error: %s\n", s);
    return 0;
}
