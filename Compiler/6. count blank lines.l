%{
#include <stdio.h>

int blank_lines = 0;
%}

%%

^[ \t]*\n       { blank_lines++; }

.*\n             ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the text:\n");
    yylex();

    printf("\nNumber of blank lines = %d\n", blank_lines);

    return 0;
}
