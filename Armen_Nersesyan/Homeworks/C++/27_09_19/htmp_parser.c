#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

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


void parsehtml(char *);
bool is_leter(char *str);
bool str_case_compare(char *str1, char* str2);
char *trim(char *str, char *symbols, trim_mode mode, char *trailing_token);

int main() {
    char* elem = strdup("     <div   >     <h1>     Karen   </h1>   </  div  >        ");
    parsehtml(elem);
    free(elem);
    return 0;
}



void parsehtml(char *element) {

    if( true ) {
        //TODO
    }

    int start = 0;
    int end = 0;
    char* elem_type = (char*) malloc(strlen(element));
    char* element_type1 = (char*) malloc(strlen(element));
    char* element_child = (char*) malloc(strlen(element));

    element = trim(element, " \n\t", FULL_TRIM, NULL);

    if(element[0] != '<' && element[strlen(element) - 1] != '>') {
        if(is_leter(element)) {
            //TODO
        } else {
            printf("Sintax Error\n");
        }
    }

    for (int i = 0; i < strlen(element); i++) {
        if(element[i] == '>') {
            strncpy(elem_type, element + 1, i - 1);
            elem_type = trim(elem_type, " \n\t", FULL_TRIM, NULL);
            start = i;
            printf("====> |%s|\n", elem_type);
            break;
        }
    }

    for(int i = strlen(element) - 1; i != 0; --i) {
        if(element[i] == '<') {
            if(element[i+1] != '/'){
                printf("Sintax Error\n");
                free(elem_type);
                free(element_type1);
                return;
            }
            strncpy(element_type1, element + i, strlen(element) - i);
            end = i;
            break;
        }
    }

    trim(element_type1," </\n\t",START_TRIM,NULL);
    trim(element_type1," >\n\t",END_TRIM,NULL);

    if(!str_case_compare(elem_type,element_type1)) {
        printf("Sintax Error\n");
        free(elem_type);
        free(element_type1);
        return;
    }

    if(str_case_compare(elem_type, "button") ||
       str_case_compare(elem_type, "h1") ||
       str_case_compare(elem_type, "h1") ||
       str_case_compare(elem_type, "p") ||
       str_case_compare(elem_type, "title") ||
       str_case_compare(elem_type, "div") ) {
    } else {
        printf("Sintax Error\n");
        free(elem_type);
        free(element_type1);
        return;
    }

    free(elem_type);
    free(element_type1);
    free(element_child);

    strncpy(element_child,element + start + 1, end - start - 1 );


    if(is_leter("zzz")) {
        printf("text\n");
        return;
    } else {
        printf("not tex\n");
    }
    printf("CHILD------> |%s|\n",element_child);

    //TODO
}



bool is_leter(char *str) {
    for(int i = 0; i < strlen(str); ++i){
        // if( !(str[i]  > 'A' && str[i] < 'Z') || !(str[i]  > 'a' && str[i] < 'z')  ) {
        //        return false;
        // }
    }
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
