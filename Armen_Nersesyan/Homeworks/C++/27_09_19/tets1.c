#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum element_type {
    DIV,
    H1,
    TITLE,
    BUTTON,
    TEXT,
    UNKNOWN
} element_type;

typedef enum trim_mode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} trim_mode;

typedef struct web_element
{
    element_type type;
    char *value;
} web_element;

bool html_validator(char *element);
bool str_case_compare(char *str1, char* str2);
char *trim(char *str, char *symbols, trim_mode mode, char *trailing_token);

int main(){

    char *element = "<TITLE<><>>  sdcdfds </title<><>>";

    if(html_validator(element)) {
        printf("valid html\n");
    } else {
        printf("invalid html\n");
    }


    return 0;
}
bool html_validator(char *element) {
    int index = 0;
    int array_at_index[20];
    char* element_type = (char*)malloc(10);
    char* element_type1 = (char*)malloc(10);
    element = trim(element," ",FULL_TRIM,NULL);
    if (element[0] != '<') {
        return false;
    }
    for(int i = 0; i < strlen(element); ++i){
        if('<' == element[i] || '>' == element[i]){
            array_at_index[index] = i;
            ++index;
        }
    }
    for(int i = 0; i < index; ++i){
        printf("%d\n",array_at_index[i]);
       // printf("%c",array_symbols[i]);
    }
    if(element[array_at_index[0]] == '>'){
        return false;
    }
    printf("index ------------- %d\n",index);
    for(int i = 0, j = index/2; i < index/2, j < index; ++i,++j){
        if(element[array_at_index[i]] != element[array_at_index[j]]){
            return false;
        }
    }
    //
    //printf(" element type : %s\n",element_type);
    //printf(" element type : %s\n",element_type1);
    //if(element_type1[0] == '/'){
    //    element = trim(element_type1,"/",FULL_TRIM,NULL);
    //}
    //if(strlen(element_type) != strlen(element_type1)){
    //    return false;
    //}
    //if(element_type != "h1" && element_type == "H1" && element_type != "p" && element_type != "P"
    //    && element_type != "text" && element_type != "TEXT" && element_type != "button" && 
    //    element_type != "BUTTON" && element_type != "title" && element_type != "TITLE"){
    //    return false;
    //}
    //return str_case_compare(element_type,element_type1);
    //printf("11111111111111");
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

