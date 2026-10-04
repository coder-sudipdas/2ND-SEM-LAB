%{
#include <stdio.h>
int char_count = 0;
int word_count = 0;
int sentence_count = 0;
int line_count = 0;
%}

%%
\n              { char_count++; line_count++; }
[.!?]           { char_count++; sentence_count++; }
[a-zA-Z0-9]+    { char_count += yyleng; word_count++; }
.               { char_count++; }
%%

int main() {
    printf("Enter text:\n");
    yylex();
    printf("\n--- Results ---\n");
    printf("Characters : %d\n Words      : %d\nSentences  : %d\nLines      : %d\n", char_count,word_count,sentence_count,line_count);
    return 0;
}

int yywrap() {
    return 1;
}


