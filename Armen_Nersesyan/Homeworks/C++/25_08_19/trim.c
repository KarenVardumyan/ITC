#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include stdbool.h>

typedef enum TrimMode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} TrimMode;

char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token);
bool search(char* zangvac,char simvol);


int main() {

    char *str = (char *) malloc(100);
    str = strcpy(str, "           aaaaaaaaaaaaaaaaaaaaaaaaaaaaa    %@ ");

	//printf("%d",strlen(str));

    char *trailing_token = (char *) malloc(strlen(str));



    printf("str : |%s|\naddres : %p\n", str,str);
    str = trim(str, " ,\\#~!@#$%^&*()_\t;\"", end_TRIM, trailing_token);
   // printf("\nstr : |%s|\naddres : %p\n", str, str);

    //printf("\n\ntrailing token : |%s|\n", trailing_token);

    //free(trailing_token); trailing_token = NULL;
    //free(str); str = NULL;

    return 0;
}


/*
* Trim the given string with the given symbols2
* str - input string
* symbols - the symbols which should be removed
* mode - the trim mode, can be FULL_TRIM, END_TRIM, START_TRIM
* trailing_token - string containing trailing characters which were trimmed
*/
char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token) {
	switch(mode) {
		case FULL_TRIM:
			printf("case 1");
			break;
		case START_TRIM:
			for(int i = 0; i < strlen(str);++i){
				if(str[i] != ' ' || str[i] != '#' || str[i] != '~'){
					str = strcopy();
				}
			}
			printf("case 2");

			break;
		case END_TRIM:
			printf("case 3");
			break;

	}
}

bool search(char* zangvac,char simvol){
	for(int i = 0; i < strlen(zangvac);++i){
		if(zangvac[i] == simvol){
			return true;
		}
	}
	return false;
}

