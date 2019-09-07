#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 80
bool is_equal(char *str1, char* str2);

int main(int argc, char const *argv[]) {

    char* text1 =  (char*)malloc(SIZE);
    text1 = strcpy(text1,"armenn");

    char* text2 =  (char*)malloc(SIZE);
    text2 = strcpy(text2,"anasun");

     if(is_equal(text1,text2)) {
         printf("EQUAL\n");
     } else {
         printf("NOT EQUAL\n");
     }

    free(text1);
    free(text2);

    return 0;
}

bool is_equal(char *str1, char* str2) {
    if(strlen(str1) != strlen(str2)){
        return false;
    }
    for(int i = 0; i < strlen(str1); ++i){
        if((int)str1[i] == (int)str2[i] ||
           (int)str1[i] == (int)str2[i] + 32 ||
           (int)str1[i] == (int)str2[i] - 32) {
            return true;
        } else {
            return false;
        }
    }

}
