#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool comparison(char* str1,char* str2);
void sort_string(char** string,int value);

int main(){
    char** mystring = (char**)malloc(5);
    char *str0 = "armen";
    char *str1 = "valod";
    char *str2 = "karen";
    char *str3 = "peto";
    char *str4 = "beno";
    mystring[0] = strdup(str0);
    mystring[1] = strdup(str1);
    mystring[2] = strdup(str2);
    mystring[3] = strdup(str3);
    mystring[4] = strdup(str4);
    mystring[0] = strdup(str0);
    sort_string(mystring,5);
    for(int i = 0; i < 5; ++i){
        printf("%s\n",mystring[i]);
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
void sort_string(char** string,int value){
    char*  temp = NULL;
    for(int tmp = 0; tmp < value; ++tmp){
        for(int i = 0, j = i + 1; i < value - 1, j < value ; ++i, ++j){
            if(comparison(string[i],string[j]) == false){
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}