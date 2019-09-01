#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int main(int argc, char const *argv[]) {

    char *text;

    text = (char *) malloc(100);
    strcpy(text, "aaaaaaaaaaaaa");


    char *text1 = strdup(text);
    printf("text 1 = |%s|\n", text1);


    free(text1);
    free(text);

    return 0;
}

