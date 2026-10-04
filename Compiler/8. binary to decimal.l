%{
#include <stdio.h>

int decimal = 0;
%}

%%

[01]+ {
    decimal = 0;

    for (int i = 0; yytext[i] != '\0'; i++)
    {
        decimal = decimal * 2 + (yytext[i] - '0');
    }

    printf("Decimal Equivalent = %d\n", decimal);
}

[ \t\n]+ ;

. {
    printf("Invalid Binary Number\n");
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a binary number: ");
    yylex();

    return 0;
}

