%option noyywrap
%{
%}
%%
. ECHO;
%%
int main() {
    yylex();
    printf("Program ends\n");
    return 0;
}
