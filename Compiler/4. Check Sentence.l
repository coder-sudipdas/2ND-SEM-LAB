%{
	#include<stdio.h>

%}

%%
.*\? {printf("\nInterrogative Sentence.\n");}
.*\. {printf("\nDeclarative Sentence.\n");}
%%
int main()
{
	printf("\nEnter a sentence:\n");
	yylex();
	return 0;
}

int yywrap()
{
return 1;
}


