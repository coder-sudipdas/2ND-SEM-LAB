%{
#include <stdio.h>
%}

%%
^[ \t]*#[ \t]*define[^\n]*\n ;
.|\n fprintf(yyout, "%s", yytext);
%%

int main()
{
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Macros removed successfully.\n");
    return 0;
}

int yywrap()
{
    return 1;
}
