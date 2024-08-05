%option noyywrap
%{
#include<stdio.h>
int s=0;
%}

%%
she {s++; REJECT;};
he {s++;}
%%
int main()
{
yyin=stdin;
yylex();
printf("%d\n",s);
return 0;
}
