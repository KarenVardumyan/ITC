#include <iostream>

class List {
    
    struct Node {
        Node* next;
        int value;
        Node(int v,Node* node = nullptr):value(v),next(node) { }
    };
    
    int size;
    Node* head;
    Node* tail;
    
    public:
    
    List() {
        this -> size = 0;
        this -> head = nullptr;
        this -> tail = nullptr;
    }

    List(int size,int value = 0) {
        this -> size = 0;
        this -> head = nullptr;
        this -> tail = nullptr;
        for(int i = 0; i < size; ++i) {
            push_back(value);
        }
    }

    ~List() { clear(); }
    
    int get_size() const { return size; }  
    
    void clear() {
        while(size) {
            pop_front();
        }
    }
    
    int& operator[](const int index) {
        Node* tmp = head;
        for(int i = 0; i <= index; ++i) {
            if(i == index) {
                return tmp -> value;
            }
            tmp = tmp -> next;
        }
    }
    
    void insert_at_index(int value,int index){
        if(index == 0) {
            head  = new Node(value,head);
        }
        else {
            Node* tmp = head;
            for(int i = 0; i < index - 1; ++i) {
                tmp = tmp -> next;
            }
            tmp -> next = new Node(value,tmp -> next);
        }
        ++size;
    }
    
    int get_at_index(int index) {
        Node* tmp = head;
        for(int i = 0; i < index; ++i){
            tmp = tmp -> next;
        }
        return tmp -> value;
    }

    void set_at_index(int index,int value) {
        Node* tmp = head;
        for(int i = 0; i < index; ++i){
            tmp = tmp -> next;
        }
        tmp -> value = value;
    }

    void push_back(int value) {       
        if(size == 0) {
            head = new Node(value);
            tail = head;
        } 
        else {
            Node* tmp  = head;
            while(tmp -> next != nullptr) {
                tmp = tmp -> next;
            }
            tmp -> next = new Node(value);
            tail = tmp;
        }
        ++size;
    }
    
    void push_front(int value) {
        head = new Node(value,head);
        ++size;
    }
    
    void pop_back() {
        Node* tmp = head;
        for(int i = 0; i < size - 2; ++i) {
            tmp = tmp -> next;
        }
        delete tmp -> next;
        tmp -> next = nullptr;
        --size;
    }
    
    void pop_front() {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
        --size;
    }
    
    int list_max() const {
        Node* tmp = head;
        int max = head -> value;
        for(int i = 0; i < size; ++i) {
            if(tmp -> value > max) {
                max = tmp -> value;
            }
            tmp = tmp -> next;
        }
        return max;
    }
    
    int list_min() const {
        Node* tmp = head;
        int min = head -> value;
        for(int i = 0; i < size; ++i) {
            if(tmp -> value < min) {
                min = tmp -> value;
            }
            tmp = tmp -> next;
        }
        return min;
    }
    
    void reverse() {
        Node* tmp = head;
        int counter = size;
        for(int i = 0; i < counter; ++i) {
            push_front(tmp -> value);
            tmp = tmp -> next;
        }
        for(int i = 0; i < counter; ++i) {
            pop_back();
        }
    }
    
    void print() const {
        Node* tmp = head;
        for(int i = 0; i < size; ++i) {
            std::cout << "value " << i << " = " << tmp -> value << std::endl;
            tmp = tmp -> next;
        }
    }
    
};