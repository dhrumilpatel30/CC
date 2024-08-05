%option noyywrap
%{
#include <stdio.h>
#include <string.h>

char prev_string[100] = "";
char curr_string[100];

int in_order = 1;

%}

%%
[A-Za-z]+       { 
                    strcpy(curr_string, yytext);
                    if (strcmp(prev_string, "") != 0 && strcmp(curr_string, prev_string) < 0) {
                        in_order = 0;
                    }
                    strcpy(prev_string, curr_string);
                }
.               { }

%%

int main() {
    yylex();

    if (in_order) {
        printf("Strings are in lexicographical order.\n");
    } else {
        printf("Strings are NOT in lexicographical order.\n");
    }

    return 0;
}