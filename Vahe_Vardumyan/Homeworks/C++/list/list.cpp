#include<iostream>

template<typename T>
List<T>::List(void) {
    std::cout<< "Default constructor" <<std::endl;
}

template<typename T>
List<T>::List(unsigned int size) {
    std::cout<< "Parametrize constructor, size = " << size <<std::endl;
}

template<typename T>
List<T>::~List() {
    std::cout<< "Destructor" <<std::endl;
}

