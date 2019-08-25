#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef enum TrimMode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} TrimMode;

char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token);
bool is_not_contain_char(char *str, char symbol);


int main() {

    char *str = (char *) malloc(100);
    str = strcpy(str, "  %&%%%&&%&%&%&%&&% karen armen arto  %@ ");


    char *trailing_token = (char *) malloc(strlen(str));



    printf("str : |%s|\naddres : %p\n", str,str);
    str = trim(str, " %@&", START_TRIM, trailing_token);
    printf("\nstr : |%s|\naddres : %p\n", str, str);

    printf("\n\ntrailing token : |%s|\n", trailing_token);

    free(trailing_token); trailing_token = NULL;
    free(str); str = NULL;

    return 0;
}


/*
* Trim the given string with the given symbols
* str - input string
* symbols - the symbols which should be removed
* mode - the trim mode, can be FULL_TRIM, END_TRIM, START_TRIM
* trailing_token - string containing trailing characters which were trimmed
*/
char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token) {
    int cutbegin = 0;
    int cutend = 0;

    for(int i = 0; i < strlen(str); ++i) {
        if (is_not_contain_char(symbols, str[i])) {
            break;
        }
        cutbegin++;
    }
    printf("cutbegin = %d\n", cutbegin);

    for(int i = strlen(str) - 1; i > 0; --i) {
        printf("gfgfgfg\n");
        if (is_not_contain_char(symbols, str[i])) {
            break;
        }
        cutend++;
    }


    printf("cutend = %d\n", cutend);

    switch (mode) {
        case(START_TRIM):
            memmove(str,
                    str + cutbegin,
                    cutbegin);
        break;
    }
}

bool is_not_contain_char(char *str, char symbol) {
    for(int i = 0; i < strlen(str); ++i) {
        if( *(str + i) == symbol) {
            return false;
        }
    }
    return true;
}