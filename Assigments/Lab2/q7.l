%option noyywrap
%{
#include <stdio.h>

int shift = 3; 
%}

%%
[a-z]          { printf("%c", (yytext[0] - 'a' + shift) % 26 + 'a'); }
[A-Z]          { printf("%c", (yytext[0] - 'A' + shift) % 26 + 'A'); }
.|\n           { printf("%s", yytext); }
%%

int main() {
    yylex();

    return 0;
}