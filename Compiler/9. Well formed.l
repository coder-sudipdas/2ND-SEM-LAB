%{
#include <stdio.h>

int count = 0;
int valid = 1;
%}

%%

"("     { count++; }

")"     {
          count--;

          if (count < 0)
          {
              valid = 0;
          }
        }

\n      {
          if (count == 0 && valid == 1)
              printf("Parentheses are Well-Formed\n");
          else
              printf("Parentheses are Not Well-Formed\n");

          return 0;
        }

.       ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter an expression: ");
    yylex();

    return 0;
}




