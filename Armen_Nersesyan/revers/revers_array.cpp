#include<iostream>
#include<string.h>
#include<stdlib.h>

void revers(void* array, int size, int length);

int main(int argc, char const *argv[]) {

    int length;
    std::cout<< "\nInput the length of the arrays => ";
    std::cin>> length;


    //The array of integers
    int* integers = (int *) malloc(sizeof(int) * length);
    std::cout<< "\n\nInput the integers => ";
    for(int i = 0; i < length; ++i) {
        std::cin>> integers[i];
    }

    //The array of characters
    char* characters = (char *) malloc(sizeof(char) * length);
    std::cout<< "Input the characters => ";
    for(int i = 0; i < length; ++i) {
        std::cin>> characters[i];
    }

    //The array of the long integers
    long int* longIntegers = (long int *) malloc(sizeof(long int) * length);
    std::cout<< "Input the long integers => ";
    for(int i = 0; i < length; ++i) {
        std::cin>> longIntegers[i];
    }


    std::cout<< "\n\n\n=============== Before the revers ===============\n\nIntegers        ";
    for(int i = 0; i < length; ++i) {
        std::cout<< integers[i] << " ";
    }
    std::cout<< "\nCharacters      ";
    for(int i = 0; i < length; ++i) {
        std::cout<< characters[i] << " ";
    }
    std::cout<< "\nLong integers   ";
    for(int i = 0; i < length; ++i) {
        std::cout<< longIntegers[i] << " ";
    }
    std::cout<< "\n\n";


    revers(integers, sizeof(integers[0]), length);
    revers(characters, sizeof(characters[0]), length);
    revers(longIntegers, sizeof(longIntegers[0]), length);


    std::cout<< "\n\n\n=============== After the revers ===============\n\nIntegers        ";
    for(int i = 0; i < length; ++i) {
        std::cout<< integers[i] << " ";
    }
    std::cout<< "\nCharacters      ";
    for(int i = 0; i < length; ++i) {
        std::cout<< characters[i] << " ";
    }
    std::cout<< "\nLong integers   ";
    for(int i = 0; i < length; ++i) {
        std::cout<< longIntegers[i] << " ";
    }
    std::cout<< "\n\n";


    free(integers);
    free(characters);
    free(longIntegers);
    return 0;
}

/**
 * Reverses an any array independent from the types of the elements
 * array - The address of the first element of the array
 * size - The size of one element in the array in bytes
 * length - The count of array elements
 */
void revers(void* array, int size, int length) {
    void* first = array;
    void* last = array + (length - 1) * size;
    void* buffer = malloc(size);
    for(int i = 0; i < length / 2; ++i) {
        memcpy(buffer, first, size);
        memcpy(first, last, size);
        memcpy(last, buffer, size);
        first = first + size;
        last = last - size;
    }
    free(buffer);
}
