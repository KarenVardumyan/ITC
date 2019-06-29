#include "list.hpp"
#include <iostream>

int main() {
    
    List<char> list1(11,'f');
    List<char> list2(3,'z');
    List<char> listsum;
     list1.pop_back();
     list1.pop_front();
     list1.push_back('b');
     list1.push_back('c');
     list1.push_back('d');
     list1.set_at_index('a',-6);
     list1.remove_at_index(100);
    
    if(list1 != list2) {
        std::cout << "lists are not equal!\n";
    }
    else {
        std::cout << "list1 = list2\n";
    }
    
    listsum = list1 + list2;
     std::cout << "Max value of list = " << list1.list_max() <<std::endl;
     std::cout << "Min value of list = " << list1.list_min() <<std::endl;
     std::cout << "Size of list = " << listsum.get_size() << std::endl;
    listsum.print();
    // list2.print();
    
    return 0;
}
