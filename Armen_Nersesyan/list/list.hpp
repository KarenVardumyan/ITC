#ifndef _LIST_H_
#define _LIST_H_
template<typename T>

class List{
    private:
    struct Node{
        Node* next;
        T value;
    };
    Node* head;
    Node* tail;
    int size = 0;
    public:
    List();
    int get_size(void);
    void push_back(T value);
    void pop_back(void);
    void push_front(T value);
    void pop_front(void);
    void print(void);
    void clear(void);
    void insert_at_index(unsigned index,T value);
    T operator[](unsigned int index);
    List(int count);
    ~List();
};
#include"list.tpp"
#endif