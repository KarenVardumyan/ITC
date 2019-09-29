#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
button
div
h1
p
title
*/

typedef enum trim_mode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} trim_mode;

bool html_validator(char *element);
bool str_case_compare(char *str1, char* str2);
char *trim(char *str, char *symbols, trim_mode mode, char *trailing_token);


int main(int argc, char const *argv[]) {

    char *element = "<div>  sdcdfds </div>";

    if(html_validator(element)) {
        printf("valid html\n");
    } else {
        printf("invalid html\n");
    }

    return 0;
}




bool html_validator(char *element) {
    int index = 0;
    char* element_type = (char*)malloc(10);
    element = trim(element," ",FULL_TRIM,NULL);
    if (element[0] != '<') {
        return false;
    }


    element = trim(element, " ", FULL_TRIM, NULL);
    bool a = false;
    for(int i = 0; i < strlen(element); ++i){
       if('>' == element[i]) {
            index = i - 1;
            break;
       }
    }
    strncpy(element_type, element + 1 ,index);
    element_type = trim(element_type, " ", FULL_TRIM, NULL);


    printf(" element type : %s\n",element_type);
    // printf("%s\n", element);

    return true;
}

















char *trim(char *str, char *symbols, trim_mode mode, char *trailing_token) {

    if (str == NULL || symbols == NULL || *str == '\0' || *symbols == '\0') {
        return str;
    }

    bool symbols_element_type[255] = {false};
    for(int i = 0; i <  strlen(symbols); ++i) {
        symbols_element_type[ (int) symbols[i] ] = true;
    }

    switch(mode) {
        case FULL_TRIM:
        case START_TRIM: {
            int heading_count = 0;
            for (int i = 0; i < strlen(str); ++i) {
                if (!symbols_element_type[ (int) str[i] ]) {
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
                if (!symbols_element_type[ (int) str[i] ]) {
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

bool str_case_compare(char *str1, char* str2) {

    if(strlen(str1) != strlen(str2)) {
        return false;
    }

    for(int i = 0; i < strlen(str1); ++i) {
        if((int)str1[i] != (int)str2[i] && (int)str1[i] + 32 != (int)str2[i] &&
           (int)str1[i] - 32 != (int)str2[i]) {
            return false;
        }
    }

    return true;
}
