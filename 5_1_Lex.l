%{
%}
DIGIT [0-9]
FLOAT_NUM {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)? 
STRING \"([^\"\\]|\\.)*\"
%%
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"=" { return EQ; }
"(" { return LPAREN; }
")" { return RPAREN; }
{DIGIT}+ { return INT; }
{FLOAT_NUM} { return FLOAT; }
{STRING} { return STRING; }
%%
int yywrap() {
    return 1;
}
