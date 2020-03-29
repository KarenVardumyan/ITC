#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void trim(char* str1);
char** split(char* inputString,char token,int* count);
void del(char** str,int length);
int main(){
    char token = ' ';
    int count = 0;
    char inputString[] ="gggg kjjnjnh fgf djkfndj djfn mdf md msdms smdms kdmsdf";
    if(inputString[0] == ' ' || inputString[strlen(inputString)-1] == 0){
        trim(inputString);
    }
    char** output = split(inputString,token,&count);
    for (int i = 0; i <=count ; i++) {
        printf("arr[%d] = %s\n", i, output[i]);
    }
    del(output,count);
    for (int i = 0; i <=count ; i++) {
        printf("arr[%d] = %s\n", i, output[i]);
    }
    return 0;
}

char** split(char* inputString,char token,int* count){
    int buffer = 0;
    int start = 0;
    int end = 0;
    int index = 0;
    int countSplit = 0;
    int length = strlen(inputString);
    for(int i = 0; i < length; ++i){
        if(inputString[i] == token){
            ++countSplit;
        }
        if(inputString[i] == ' '){
            ++buffer;
        }
    }
    if(buffer == length || length == 0){
        std::cout<<"empty string"<<std::endl;
        return 0;
    }
    *count = countSplit;
    char** outputString = (char**)malloc(countSplit * sizeof(char*));
    for(int i = 0; i < length; i++){
        if(inputString[i] == token || inputString[i+1] == '\0') {
            end = i;
            outputString[index] = (char*) malloc(end- start + 1);
            memmove(outputString[index], inputString + start + 1, end - start);
            start = end;
            ++index;
        }
    }
    return  outputString;
}
void trim(char* str1){
    int temp = 0;
    int stringSize = strlen(str1);
    if(str1[0] == ' '){
        while(str1[temp] == ' '){
            ++temp;
        }
        memmove(str1,str1 + temp,stringSize - temp);
        str1[stringSize - temp] = '\0';
    }
    temp = strlen(str1) - 1;
    if(str1[temp] == ' '){
        while(str1[temp] == ' '){
            --temp;
        }
        str1[temp + 1] = '\0';
    }
    return;
}
void del(char** str,int length){
    for(int i = length; i != 0; --i){
        free(str[i]);
        str[i] = NULL;
    }
    free(str);
}