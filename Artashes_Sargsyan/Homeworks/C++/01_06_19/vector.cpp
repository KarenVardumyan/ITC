#include "vector.hpp"

int main () {
    Vector<char> vector;
    // Vector<int> vector1;
    vector.push_back('e');
    vector.push_back('d');
    vector.push_back('c');
    vector.push_back('b');
    vector.push_back('a');
    // Vector<int> vector1(10,55);
    // Vector<int> vector2(5,11);
    // vector1.push_back(1);
    // vector1.swap(1,5);
    // vector1.swap(vector1,1,2);
    // vector1.swap(vector2);
    // vector.push_front(0);
    // vector.pop_back();
    // vector.pop_front();
    // vector.pop_at_index(-1);
    // vector.pop_back();
    // vector.get_at_index(255);
    // vector.insert_at_index(255,255);
    // vector.set_at_index(255,255);
    vector.sort(0);
    // vector.clear();
    // vector.shrink_to_fit();
    vector.print();
    // vector1.print();
    // vector2.print();
    
    // std::cout << "Max value of vector = " << vector.get_max() << std::endl;
    // std::cout << "Min value of vector = " << vector.get_min() << std::endl;
    // std::cout << "Vector size = " << vector.get_size() << std::endl;
    // std::cout << "Vector capacity = " << vector.get_capacity() << std::endl;
    
    return 0;
}




