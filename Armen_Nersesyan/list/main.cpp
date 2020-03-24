#ifndef _IOSTREAM_
#define _IOSTREAM_

#include"list.hpp"

int main(){
    List<int> list;
    //list.push_back(2);
    //list.get_size();
    list.push_front(50);
    list.push_back(200);
    //list.push_back(5);
    list.insert_at_index(-1,9000);
    list[0];
    list.print();

    return 0;
}

#endif