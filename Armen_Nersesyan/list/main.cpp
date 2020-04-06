#ifndef _IOSTREAM_
#define _IOSTREAM_

#include"list.hpp"

int main(){
    List<int> list;
    //list.push_back(2);
    //list.get_size();
    //list.push_front(50);
    //list.push_back(200);
    //list.push_back(5);
    //list.insert_at_index(-1,9000);
    //list[0];
    for (int i = 0; i < 10; i++){
        list.push_back(i * 5);
    }
    List<int> object(list);
    object.push_back(50000);
    list.pop_back();
    list.print();
    object.print();

    return 0;
}

#endif