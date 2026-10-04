%{
#include <stdio.h>

int id_count = 0;
int int_count = 0;
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*    { 
                            printf("Identifier: %s\n", yytext);
                            id_count++;
                          }

[0-9]+                    { 
                            printf("Integer Constant: %s\n", yytext);
                            int_count++;
                          }

[ \t\n]+                  ;

.                         ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the input text:\n");
    yylex();

    printf("\nNumber of Identifiers = %d\n", id_count);
    printf("Number of Integer Constants = %d\n", int_count);

    return 0;
}
