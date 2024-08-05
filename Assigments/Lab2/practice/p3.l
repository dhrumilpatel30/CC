%option noyywrap
%{
#include<stdio.h>
%}
letter [A-Z]
%%
{letter}+ { printf("Letter Read");}
%%
int main() {
yyin=fopen("test.txt","r");
yylex();
printf("Program ends\n");
return 0;
}
