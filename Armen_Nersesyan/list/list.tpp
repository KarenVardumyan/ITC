#include"list.hpp"
#include<iostream>
template<typename T>
List<T>::List(){
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;

}
template<typename T>
List<T>::List(int count){
    if(count == 0){
        this -> size = 0;
        this -> head = nullptr;
        this -> tail = nullptr;
    }
    while(count != 0){
        push_back(0);
        --count;
    }
}
template<typename T>
void List<T>::push_back(T value){
    if(size == 0){
        Node* newNode = new Node();
        this->head = newNode;
        this->tail = newNode;
        newNode->value =value;
        newNode->next = nullptr;
    }else{
        Node* temp = this->head;
        for(int i = 0; temp -> next != nullptr;++i){
            temp = temp->next;
        }
        Node* newNode = new Node();
        temp -> next = newNode;
        this -> tail = newNode;
        newNode -> value = value;
        newNode -> next = nullptr;
    }
    ++this->size;
}
template<typename T>
void List<T>::print(void){
    if(this -> size == 0){
        std::cout<<"the list is empty"<<std::endl;
        return;
    }
    Node* temp = this-> head;
    for(int i = 0;temp -> next != 0; ++i){
        std::cout<<temp -> value<<std::endl;
        temp = temp -> next;
    }
    std::cout<<temp -> value<<std::endl;
}
template<typename T>
int List<T>::get_size(void){
    return this->size;
}
template<typename T>
void List<T>::pop_back(void){
    if(this->size == 0){
        std::cout<<"the list is empty"<<std::endl;
        return;
    }
    Node* temp = this->head;
    for(int i = 0; i < this->size - 2; ++i){
        temp = temp -> next;
    }
    delete temp->next;
    temp->next =nullptr;
    this ->tail = temp;
    --this->size;
}
template<typename T>
void  List<T>::push_front(T value){
    if(this->size == 0){
        Node* newNode = new Node();
        this-> head = newNode;
        this-> tail = newNode;
        newNode-> value = value;
        newNode -> next = nullptr;
    }else{
        Node* newNode = new Node();
        newNode->value =value;
        newNode->next = head;
        this->head = newNode;
    }
    ++this->size;
}
template<typename T>
void List<T>::pop_front(void){
    if(this->size == 0){
        std::cout<<"the list is empty"<<std::endl;
        return;
    }else{
        Node* temp = this->head;
        head = head->next;
        delete temp;
        --this->size;
    }
}
template<typename T>
void List<T>::clear(void){
    if(this->size == 0){
        std::cout<<"the list is empty"<<std::endl;
        return;
    }else{
        pop_front();
    }
}
template<typename T>
T List<T>::operator[](unsigned int index){
    int a = 0;
    if(index < 0 || index >= size){
        std::cout<<"size list-->"<<size<<"  No souch list["<<index<<"] indexing from scratch and unsigned int"<<std::endl;
        return 0;
    }
    Node* temp = this->head;
    for(int i = 0; i < index; ++i){
        temp = temp -> next;
    }
    std::cout<<temp->value<<std::endl;
    return temp->value;
}
template<typename T>
void List<T>::insert_at_index(unsigned int index,T value){
    if(index >= size){
        std::cout<<"size list-->"<<size<<"  No souch list["<<index<<"] indexing from scratch and unsigned int"<<std::endl;
        return ;
    }
    Node* temp = this-> head;
    for(int i = 0; i < index; ++i){
        temp = temp -> next;
    }
    temp-> value = value;
}
template<typename T>
List<T>::~List(){
    clear();
}