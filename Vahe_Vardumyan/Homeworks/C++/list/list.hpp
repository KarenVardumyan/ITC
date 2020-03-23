template<typename T>

class List {
    struct Node {
        T value;
        Node* next;
    };

    unsigned int size;
    Node* head;
    Node* tail;

    public:
    List();
    List(unsigned int size);
    ~List();
};

#include "list.cpp"