%option noyywrap
%{
#include <stdio.h>
%}

%%
(00|11)[01]*        { printf("Accepted: %s\n", yytext); }
[01]*(00|11)        { printf("Accepted: %s\n", yytext); }
.                   { printf("Not Accepted: %s\n", yytext); }

%%

int main() {
    yylex();

    return 0;
}