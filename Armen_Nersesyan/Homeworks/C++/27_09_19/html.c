#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define LINES_LOUNT 10
#define LINE_LENGTH 100

typedef enum element_type {
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

typedef struct web_element {
    element_type type;
    char * value;
} web_element;

void  tags(char* tag, web_element *element);
bool str_case_compare(char *str1, char* str2);
char *trim(char *str, char *symbols, trim_mode mode, char *trailing_token);

int main(int argc, char const *argv[]){

    web_element elements[LINES_LOUNT];

    char *buf = (char *) malloc(LINE_LENGTH);
    FILE *fp;

    int rw = access("./index.html", R_OK);
    if (rw != 0) {
        printf("\n*** ERROR: Permission denied ***\n");
        return 0;
    }

    fp = fopen("./index.html", "r+");
    if (fp == NULL) {
        printf("\n*** ERROR: Could not open file for writing ***\n");
        return 0;
    }

    int i = 0;
    while(!feof(fp)) {
        fgets (buf, LINE_LENGTH, fp);
        tags(buf, &elements[i]);
        ++i;
    }

    for (int i = 0; i < LINES_LOUNT; ++i) {
        printf("===================\n");
        printf("type : %d\ndata : %s\n", elements[i].type, elements[i].value);
    }

    for (int i = 0; i < LINES_LOUNT; ++i) {
        free(elements[i].value);
    }
    fclose(fp);
    free(buf);

    return 0;
}

void  tags(char* tag, web_element *element){

    char *element_type = (char *) malloc(10);

    tag = trim(tag, " ", FULL_TRIM, NULL);
    int index = 0;
    bool a = false;
    for(int i = 0; i < strlen(tag); ++i){
       if('>' == tag[i]) {
            index = i - 1;
            break;
       }
    }
    strncpy(element_type, tag + 1 ,index);
    element_type = trim(element_type, " ", FULL_TRIM, NULL);

    if(str_case_compare(element_type, "button")) {
        element -> type = BUTTON;
    } else if(str_case_compare(element_type, "h1")) {
        element -> type = H1;
    } else if(str_case_compare(element_type, "p")) {
        element -> type = TEXT;
    } else if(str_case_compare(element_type, "title")) {
        element -> type = TITLE;
    } else {
        element -> type = UNKNOWN;
    }

    int data_length = index;
    for(int i = index + 1; i < strlen(tag);++i){
        if(tag[i] == '<'){
            index = i - 1;
            break;
        }
    }

    element -> value  = (char*)malloc(index - data_length);
    strncpy(element -> value, tag + data_length + 2, index - data_length - 1);
    element -> value = trim(element -> value, " ", FULL_TRIM, NULL);

    free(element_type);
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
