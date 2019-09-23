#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char**  split(char* str,char symbol, int* count);
void destroy(char**);

int main(int argc, char const *argv[]) {

    char symbol = ' ';
    // scanf("%c",&symbol);
    int count = 0;
    char *str = "karen armen vahe peto beno";

    char **result = split(str,symbol, &count);
    // for (int i = 0; i < count; i++) {
    //     printf("arr[%d] = %s\n", i, result[i]);
    // }


    return 0;
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
            printf("========> %s\n",arr[0]);
            b = i + 1;
            ++index;
        }
    }

    return arr;
}











