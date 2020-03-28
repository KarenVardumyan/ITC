#include <iostream>
#include <iostream>
#include <stdio.h>
#include <cstring>

void reverse(void* arr, int size,int memsize) {
    int Begin_p = 0;
    int End_p = (size * memsize) - memsize;
    void* temp = (void*) std::malloc(memsize);
    for(int i = 0; i < size/2; ++i) {
        memmove(temp, arr + Begin_p, memsize);
        memmove(arr + Begin_p, arr + End_p, memsize);    
        memmove(arr + End_p, temp, memsize);
        Begin_p = Begin_p + memsize;
        End_p = End_p - memsize;
    }
    free(temp);
}

int main() {
    
    int size = 0;
    
    std::cin >> size;
    
    int* array = new int[size];

    for(int i = 0; i < size; ++i) {
        array[i] = i;
    }
    
    for(int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
    
    reverse(array, size, sizeof(array[0]));
    
    for(int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    
    return 0;
}

