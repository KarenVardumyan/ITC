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
    str = strcpy(str, "   ##  %%@ karen armen valod poxos    %@   #    ");

    char *trailing_token = (char *) malloc(strlen(str));

    printf("str : |%s|\naddres : %p\n", str,str);
    str = trim(str, " %@#", END_TRIM, NULL);
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

	if(str == NULL || symbols == NULL || str == "" || symbols == "") {
		return str;
	}

    char ascisymbols[256] = {false};
    for (int i = 0; i < strlen(symbols); ++i) {
        ascisymbols[ (int) symbols[i] ] = true;
    }

	switch(mode) {
		case FULL_TRIM:
		case START_TRIM: {
			int counter= 0;
			for(int i = 0; i < strlen(str);++i){
				if( !ascisymbols[(int)str[i]] ){
					break;
				}
				++counter;
			}
			if(counter != 0) {
				str = memcpy(str, str + counter, strlen(str) - counter);
				str[strlen(str) - counter ] = '\0';
			}
			if(mode != FULL_TRIM){
				break;
			}
		}
		case END_TRIM: {
			int counter = 0;
			for(int i = strlen(str) - 1; i != 0 ; --i){
				if( !ascisymbols[(int)str[i]] ){
					break;
				}
				++counter;
			}
			if(trailing_token) {
				trailing_token = memcpy(trailing_token,str + (strlen(str) - counter),counter);
				str[strlen(str) - counter] = '\0';
			}
		}
	}
	return str;
}
