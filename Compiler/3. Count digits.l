%{
#include<stdio.h>
int count_digits=0, special_char=0;
%}

%%
[0-9] {count_digits++;}
[\&\#\_\-\$] {special_char++;}
\n {printf("\nNumber of digits=%d\nNumber of special characters=%d",count_digits,special_char);}

%%
int main()
{
printf("\nEnter a sentence:");
yylex();
return 0;
}
int yywrap()
{
return 1;
}



