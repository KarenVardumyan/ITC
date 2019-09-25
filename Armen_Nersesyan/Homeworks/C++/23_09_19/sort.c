#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


int main(){
    char** mystring = (char**)malloc(5);
    char *str0 = "armen";
    char *str1 = "karen";
    char *str2 = "peto";
    char *str3 = "beno";
    char *str4 = "ANVOXNASHAR";
    mystring[0] = strdup(str0);
    mystring[1] = strdup(str1);
    mystring[2] = strdup(str2);
    mystring[3] = strdup(str3);
    mystring[4] = strdup(str4);
    for(int i = 0; i < 5; ++i){
        printf("%s\n",mystring[i]);
    }
    return 0;
}