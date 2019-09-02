#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"functions.h"
#define SIZE 80
int main(int argc, char const *argv[]) {

    char* text1 =  (char*)malloc(SIZE);
    text1 = strcpy(text1,"armen");

    char* text2 =  (char*)malloc(SIZE);
    text2 = strcpy(text2,"Armen");
	
	trim(text1, " %@#$^&*()_+[]{}|'?/><", FULL_TRIM, NULL);
 	trim(text2, " %@#$^&*()_+[]{}|'?/><", FULL_TRIM, NULL);
	printf("%p",text1);
    if(is_equal(text1,text2)) {
        printf("EQUAL\n");
    } else {
        printf("NOT EQUAL\n");
    }

    free(text1);
    free(text2);
    free(text1); text1 = NULL;
    free(text2); text2 = NULL;
    return 0;
}

