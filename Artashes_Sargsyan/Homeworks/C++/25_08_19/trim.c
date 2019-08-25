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



int main() {

    char *str = (char *) malloc(100);
    str = strcpy(str, "           aaaaaaaaaaaaaaaaaaaaaaaaaaaaa    %@ ");


    char *trailing_token = (char *) malloc(strlen(str));



    printf("str : |%s|\naddres : %p\n", str,str);
    str = trim(str, " ,\\#~!@#$%^&*()_\t;\"", FULL_TRIM, trailing_token);
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
    int sizeCut = 0;
    switch (mode) {
        case(FULL_TRIM):
        for(int i = 0; i < strlen(str); ++i) {
            for(int j = 0; j < strlen(symbols); ++j) {
                if(str[i] == symbols[j]) {
                    ++sizeCut;
                }
            }
        }


        break;
    }
}