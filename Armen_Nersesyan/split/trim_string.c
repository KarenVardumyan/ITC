#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef enum TrimMode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} TrimMode;

char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token);



int main() {

    char *str = (char *) malloc(100);
    str = strcpy(str, "   # \"###\" \\ $$$#%  ^&*  &HELLO World& ##!!! ;;;;  !@#%#$^#%^*&(%*&)     ^$");
    // str = strcpy(str, "  ,         HELLO World         ;;;;");

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

    if (str == NULL || symbols == NULL || *str == '\0' || *symbols == '\0') {
        return str;
    }

    bool symbols_array[255] = {false};
    for(int i = 0; i <  strlen(symbols); ++i) {
        symbols_array[ (int) symbols[i] ] = true;
    }

    switch(mode) {
        case FULL_TRIM:
        case START_TRIM: {
            int heading_count = 0;
            for (int i = 0; i < strlen(str); ++i) {
                if (!symbols_array[ (int) str[i] ]) {
                    break;
                }
                ++heading_count;
            }
            if (heading_count != 0) {
                memmove(str, str + heading_count, strlen(str) - heading_count);
                str[strlen(str) - heading_count] = '\0';
            }
            if (FULL_TRIM != mode) {
                break;
            }
        }
        case END_TRIM: {
            int trailing_count = 0;
            for (int i = strlen(str) - 1; i >= 0; --i) {
                if (!symbols_array[ (int) str[i] ]) {
                    break;
                }
                ++trailing_count;
            }
            if (trailing_count != 0) {
                if(trailing_token != NULL) {
                    strcpy(trailing_token, str + strlen(str) - trailing_count);
                }
                str[strlen(str) - trailing_count] = '\0';
            }
            break;
        }
    }

    return str;
}