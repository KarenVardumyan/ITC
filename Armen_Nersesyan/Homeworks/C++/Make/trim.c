#include "functions.h"
#include"string.h"
#include"stdbool.h"
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
