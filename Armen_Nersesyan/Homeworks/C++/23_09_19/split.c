#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool comparison(char* str1,char* str2);
char**  split(char* str,char symbol, int* count);

int main(int argc, char const *argv[]) {

    char symbol = ' ';
    int count = 0;
    char *str = "karen armen valod babken aaaaaaa";

    char **result = split(str,symbol, &count);
    for (int i = 0; i < count; i++) {
         printf("arr[%d] = %s\n", i, result[i]);
    }


    return 0;
}
bool comparison(char* str1,char* str2){
    if(strlen(str1) == 0){
        return true;
    }
    int size_string = 0;
    if(strlen(str1) > strlen(str2)){
        size_string = strlen(str2);
    }else{
        size_string = strlen(str1);
    }
    for(int i = 0; i < size_string; ++i){
        if((int)str1[i] < (int)str2[i]){
            return true;
        }else if((int)str1[i] > (int)str2[i]){
            return false;
        }else{
            ++i;
            if( i >= size_string && strlen(str1) < strlen(str2)){
                return true;
            }
        }
    }
}

char**  split(char* str,char symbol, int* count) {

    int countsymbol = 1;
    int index = 0;
    int range = 0;
    for(int i = 0; i < strlen(str); ++i){
        if(str[i] == symbol){
            countsymbol += 1;
        }
    }
    *count = countsymbol;
    char **arr = (char**) malloc(countsymbol);

    int b = 0;

    for (int i = 0; i <= strlen(str); ++i){
        if(str[i] == symbol || str[i] == '\0'){
            arr[index] = (char*)malloc(i - b);
            strncpy(arr[index], str + b, i - b);
            b = i + 1;
            ++index;
        }
    }
    arr[0] = "karen";
    char* temp = NULL;
    for(int start = 0; start < countsymbol; ++start){
        for (int i = 0,j = 1; i < countsymbol,j < countsymbol; ++i, ++j){
            if(comparison(arr[i],arr[j]) == false){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
