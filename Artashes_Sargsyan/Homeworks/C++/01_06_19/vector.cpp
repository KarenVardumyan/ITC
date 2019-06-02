#include "vector.hpp"

int main () {
    Vector vector;
    Vector vector1;
    // Vector vector1(10,55);
    // Vector vector2(5,11);
    // vector1.push_back(1);
    vector1.swap(1,5);
    vector1.swap(vector1,1,2);
    // vector1.swap(vector2);
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
    vector.shrink_to_fit();
    vector.print();
    // vector1.print();
    // vector2.print();
    
    // std::cout << "Max value of vector = " << vector.get_max() << std::endl;
    // std::cout << "Min value of vector = " << vector.get_min() << std::endl;
    // std::cout << "Vector size = " << vector.get_size() << std::endl;
    // std::cout << "Vector capacity = " << vector.get_capacity() << std::endl;
    
    return 0;
}



