#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define LINES_LOUNT 5
#define LINE_LENGTH 100

typedef enum element_type
{
    H1,
    TITLE,
    BUTTON,
    TEXT,
    UNKNOWN
} element_type;

typedef struct web_element
{
    element_type type;
    char *value;
} web_element;

char *html_generator(web_element *data_html, char *file_path);

int main()
{
    char *file_path = "./_index.html";
    web_element elements[LINES_LOUNT];
    elements[0].type = H1;
    elements[0].value = "Ballus111";
    elements[1].type = BUTTON;
    elements[1].value = "Ballus222";
    elements[2].type = BUTTON;
    elements[2].value = "Ballus3333";
    elements[3].type = TITLE;
    elements[3].value = "Ballus444";
    elements[4].type = TEXT;
    elements[4].value = "    Ballus      5555  ";
    //for (int i = 0; i < LINES_LOUNT; ++i) {
    //    printf("===================\n");
    //    printf("type : %d\ndata : %s\n", elements[i].type, elements[i].value);
    //}
    html_generator(elements, file_path);
    return 0;
}

char *html_generator(web_element *data_html, char *file_path)
{
    FILE *adress_file;
    char *type;
    adress_file = fopen(file_path, "w");
    for (int i = 0; i < LINES_LOUNT; ++i){
        switch (data_html[i].type)
        {
        case H1:
            type = "h1";
            break;
        case TITLE:
            type = "title";
            break;
        case BUTTON:
            type = "button";
            break;
        case TEXT:
            type = "p";
            break;
        default:
            type = "unknown";
        }
        fprintf(adress_file, "<%s>  %s </%s>\n", type, data_html[i].value, type);
    }
    fclose(adress_file);
}
