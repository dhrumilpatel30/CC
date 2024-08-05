%option noyywrap
%{
#include <stdio.h>
int isValid=0;
%}

number [0-9]+
%%
{number}+ printf("Valid Numbers: %s\n", yytext);
. printf("Invalid Numbers: %s\n", yytext);
%%

int main() {
yylex(); 
  return 0; 
}