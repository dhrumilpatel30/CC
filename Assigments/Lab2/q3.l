%option noyywrap
%{
#include <stdio.h>

int a_count = 0;
int an_count = 0;
int the_count = 0;

%}

%%
"a"         { a_count++; }
"an"        { an_count++; }
"the"       { the_count++; }
.           {w}
%%

int main() {

    yylex();

    printf("Occurrences of 'a': %d\n", a_count);
    printf("Occurrences of 'an': %d\n", an_count);
    printf("Occurrences of 'the': %d\n", the_count);

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}