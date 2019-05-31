#include <iostream>
#include "vector.hpp"

int main () {

    Vector vector;
    
    // vector.push_back(1);
    // vector.push_front(0);
    vector.pop_back();
    vector.pop_front();
    vector.pop_at_index(-1);
    vector.pop_back();
    vector.get_at_index(255);
    vector.insert_at_index(255,255);
    vector.set_at_index(255,255);
    vector.sort(0);
    vector.clear();
    vector.print();

    std::cout << "Max value of vector = " << vector.get_max() << std::endl;
    std::cout << "Min value of vector = " << vector.get_min() << std::endl;
    std::cout << "Vector size = " << vector.get_size() << std::endl;
    std::cout << "Vector capacity = " << vector.get_capacity() << std::endl;
    return 0;
}



