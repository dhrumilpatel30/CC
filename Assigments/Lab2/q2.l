%option noyywrap
%{
#include <stdio.h>
%}

%%
^(00|11).*?(00|11)$ { printf("Accepted string: %s\n", w); }
.|\n               {}
%%

int main() {
    yylex();
    return 0;
}