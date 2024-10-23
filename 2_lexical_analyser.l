%{
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int|float|char|double|while|for|main|do|if|break|continue|void|switch|case|long|
struct|const|typedef|return|else|goto {printf("\n\t%s is a keyword",yytext);}
{identifier} {printf("\n\t%s is an identifier",yytext);}
[0-9]+ {printf("\n\t%s is a number",yytext);}
= {printf("\n\t%s is an assignment operator",yytext);}
\<= |
\>= |
\< |
== |
\> {printf("\n\t%s is a relational operator",yytext);}

\( |
\) |
\{ |
\} {printf("\n\t%s is a punctuation symbol",yytext);}
\+ |
\- |
\* |
\/ |
\% {printf("\n\t%s is an arithmetic operator",yytext);}
\++ |
\-- {printf("\n\t%s is an unary operator",yytext);}
. |\n
%%
int main(int argc,char **argv)
{
    if(argc>1)
    {
        FILE *f;
        f=fopen(argv[1],"r");
        if(!f)
        {
            printf("CANNOT OPEN %s\n",argv[1]);
            exit(0);
        }
        yyin=f;
    }
    yylex();
    printf("\n\n");
    return 0;
}
int yywrap()
{
    return 0;
}
