%option noyywrap
%{

int line_count = 0;
int word_count = 0;

%}

%%

\n              { line_count++; }
[A-Za-z]+       { word_count++; }
.               {}

%%

int main() {
    yyin = fopen("Assigments/Lab2/sample.txt", "r");
    yylex();

    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}