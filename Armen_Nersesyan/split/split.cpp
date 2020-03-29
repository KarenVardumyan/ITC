#include<iostream>
#include<string.h>
#include <stdlib.h>

void trim(char* str1);
char** split(char* inputString,char token,int* count);

int main(){
    char token = ' ';
    int count = 0;
    char inputString[] ="gggg kdkdk dkdkkd kdkd jnjdefj";
    if(inputString[0] == ' ' || inputString[strlen(inputString)-1] == 0){
    trim(inputString);
    }
    char** output = split(inputString,token,&count);
    for (int i = 0; i <=count ; i++) {
         printf("arr[%d] = %s\n", i, output[i]);
    }

    //for(int i = 0; i < count;++i){
    //    std::cout<<*output[i]<<std::endl;
    //}
    return 0;
}

char** split(char* inputString,char token,int* count){
    int buffer = 0;
    int start = 0;
    int index = 0;
    int countSplit = 0;
    int size = strlen(inputString);
    for(int i = 0; i < size; ++i){
        if(inputString[i] == token){
            ++countSplit;
        }
        if(inputString[i] == ' '){
            ++buffer;
        }
    }
    if(buffer == size || size == 0){
        std::cout<<"empty string"<<std::endl;
        return 0;
    }
    *count = countSplit;
    std::cout<<countSplit<<std::endl;
    std::cout<<*count<<std::endl;
    char** outputString = (char**) malloc(countSplit);
    for(int i = 0; i < size; i++){
        if(inputString[i] == token || inputString[i + 1] == '\0'){
            outputString[index] = (char*) malloc(i - start);
            memmove(outputString[index],inputString + start,i- start);
            start = i + 1;
            ++index;
        }
    }
    return outputString;
}
void trim(char* str1){
    std::cout<<"sssssssssssssssssssssss";
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