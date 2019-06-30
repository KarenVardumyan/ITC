#include<iostream>
#include"list.hpp"

template<typename T>

List<T>::List() {
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
}

template<typename T>
List<T>::List(int size,T value) {
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
    for(int i = 0; i < size; ++i) {
        push_back(value);
    }
}

template<typename T>
List<T>::List(List& copy) {
    Node<T>* tmpcopy = copy.head;
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
    for(int i = 0; i < copy.get_size(); ++i) {
        push_back(tmpcopy -> value);
        tmpcopy = tmpcopy -> next;
    }
    
}

template<typename T>
List<T>::~List() { clear(); }

template<typename T>
int List<T>::get_size() const { return size; }  

template<typename T>
void List<T>::clear() {
    while(size) {
        pop_front();
    }
}

template<typename T>
List<T> List<T>::operator+(const List<T>& lst1) {
    Node<T>* tmp = head;
    Node<T>* tmp1 = lst1.head;
    List<T> listsum;
    for(int i = 0; i < size; ++i) {
        listsum.push_back(tmp -> value);
        tmp = tmp -> next;
    }
    for(int j = 0; j < lst1.get_size(); ++j) {
        listsum.push_back(tmp1 -> value);
        tmp1 = tmp1 -> next;
    }
    return listsum;
}

template<typename T>
void List<T>::operator=(const List<T>& lst1) {
    Node<T>* tmp = head;
    Node<T>* tmp1 = lst1.head;
    int big_size = (size > lst1.get_size()) ? size : lst1.get_size();
    for(int i = 0; i < big_size; ++i) {
        if(lst1.get_size() > size && i == size) {
            push_back(tmp1 -> value);
            tmp1 = tmp1 -> next;
        }
        else if(lst1.get_size() < size && i >= lst1.get_size()) {
            pop_back();
        }
        else {
            tmp -> value = tmp1 -> value;
            tmp = tmp -> next;
            tmp1 = tmp1 -> next;
        }
    }
}

template<typename T>
const bool List<T>::operator==(const List<T>& right) {
    if(size != right.get_size()) {
        return false;
    }
    Node<T>* tmp = head;
    Node<T>* tmpright = right.head;
    for(int i = 0; i < right.get_size(); ++i) {
        if(tmp -> value != tmpright -> value) {
            return false;
        }
        tmp = tmp -> next;
        tmpright = tmpright -> next;
    }
    return true;
}

template<typename T>
const bool List<T>::operator!=(const List<T>& right) {
    if(size != right.get_size()) {
        return true;
    }
    Node<T>* tmp = head;
    Node<T>* tmpright = right.head;
    for(int i = 0; i < right.get_size(); ++i) {
        if(tmp -> value != tmpright -> value) {
            return true;
        }
        tmp = tmp -> next;
        tmpright = tmpright -> next;
    }
    return false;
}

template<typename T>
T& List<T>::operator[](const int index) {
    if(index > size || index < 0) {
        std::cout << "list[i]...out of size!\n";
    }
    Node<T>* tmp = head;
    for(int i = 0; i <= index; ++i) {
        if(i == index) {
            return tmp -> value;
        }
        tmp = tmp -> next;
    }
}

template<typename T>
void List<T>::insert_at_index(T value,int index){
    if(index == 0) {
        head  = new Node<T>(value,head);
    }
    else {
        Node<T>* tmp = head;
        for(int i = 0; i < index - 1; ++i) {
            tmp = tmp -> next;
        }
        tmp -> next = new Node<T>(value,tmp -> next);
    }
    ++size;
}

template<typename T>
T List<T>::get_at_index(int index) {
    if(index > size || index < 0) {
        std::cout << "get_at_index(int >>> " << index << " <<<)...error.\n";
        return T();
    }
    Node<T>* tmp = head;
    for(int i = 0; i < index; ++i) {
        tmp = tmp -> next;
    }
    return tmp -> value;
}

template<typename T>
void List<T>::set_at_index(T value,int index) {
    if(index > size || index < 0) {
        std::cout << "set_at_index(int >>> " << index << " <<<)...error.\n";
        return;
    }
    Node<T>* tmp = head;
    for(int i = 0; i < index; ++i) {
        tmp = tmp -> next;
    }
    tmp -> value = value;
}

template<typename T>
void List<T>::remove_at_index(int index ) {
    if(index > size || index < 0) {
        std::cout << "remove_at_index(int >>> " << index << " <<<)...error.\n";
        return;
    }
    if (index == 0) {
	    pop_front();
    }
    else {
	    Node<T> *tmp = head;
	    for (int i = 0; i < index - 1; i++) {
		    tmp = tmp -> next;
	    }	
	    Node<T> *Node_Delete = tmp -> next;
	    tmp -> next = Node_Delete -> next;
	    delete Node_Delete;
	    --size;
    }

}

template<typename T>
void List<T>::push_back(T value) {       
    if(size == 0) {
        head = new Node<T>(value);
        tail = head;
    } 
    else {
        Node<T>* tmp  = head;
        while(tmp -> next != nullptr) {
            tmp = tmp -> next;
        }
        tmp -> next = new Node<T>(value);
        tail = tmp;
    }
    ++size;
}

template<typename T>
void List<T>::push_front(T value) {
    head = new Node<T>(value,head);
    ++size;
}

template<typename T>
void List<T>::pop_back() {
    if(size == 0) {
        std::cout << "pop_back()...size = " << size << "...list is empty.\n";
        return;
    }
    Node<T>* tmp = head;
    for(int i = 0; i < size - 2; ++i) {
        tmp = tmp -> next;
    }
    delete tmp -> next;
    tmp -> next = nullptr;
    --size;
}

template<typename T>
void List<T>::pop_front() {
    if(size == 0) {
        std::cout << "pop_front()...size = " << size << "...list is empty.\n";
        return;
    }
    Node<T>* tmp = head;
    head = head -> next;
    delete tmp;
    --size;
}

template<typename T>
T List<T>::list_max() const {
    if(size == 0) {
        std::cout << "list_max()...size = " << size << "...list is empty.\n";
        return T();
    }
    Node<T>* tmp = head;
    int max = head -> value;
    for(int i = 0; i < size; ++i) {
        if(tmp -> value > max) {
            max = tmp -> value;
        }
        tmp = tmp -> next;
    }
    return max;
}

template<typename T>
T List<T>::list_min() const {
    if(size == 0) {
        std::cout << "list_min()...size = " << size << "...list is empty.\n";
        return T();
    }
    Node<T>* tmp = head;
    int min = head -> value;
    for(int i = 0; i < size; ++i) {
        if(tmp -> value < min) {
            min = tmp -> value;
        }
        tmp = tmp -> next;
    }
    return min;
}

template<typename T>
void List<T>::reverse() {
    if(size == 0) {
        std::cout << "reverse()...size = " << size << "...list is empty.\n";
        return;
    }
    Node<T>* tmp = head;
    int counter = size;
    for(int i = 0; i < counter; ++i) {
        push_front(tmp -> value);
        tmp = tmp -> next;
    }
    for(int i = 0; i < counter; ++i) {
        pop_back();
    }
}

template<typename T>
void List<T>::print() const {
    if(size == 0) {
        std::cout << "print()...size = " << size << "...list is empty.\n";
        return;
    }
    Node<T>* tmp = head;
    for(int i = 0; i < size; ++i) {
        std::cout << "value " << i << " = " << tmp -> value << std::endl;
        tmp = tmp -> next;
    }
    std::cout << std::endl;
}
