#include "functions.h"
#include"stdbool.h"
#include "string.h"

_Bool is_equal(char *str1, char* str2) {
    if(strlen(str1) != strlen(str2)){
        return false;
    }
    for(int i = 0; i < strlen(str1); ++i){
        if((int)str1[i] == (int)str2[i] ||
           (int)str1[i] == (int)str2[i] + 32 ||
           (int)str1[i] == (int)str2[i] - 32) {
           ++i;
        } else {
            return false;
        }
    }
	return true;

}
