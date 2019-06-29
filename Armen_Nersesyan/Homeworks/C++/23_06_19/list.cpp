#include<iostream>
#include<utility>
template <typename T>
// template <typename List> 

class List
{
	struct Node{
		Node* next;
		T value;
	};

	int size;
	Node* head;
	Node* tail;
	public:

	List(T value){
		Node* newNode = new Node();
		newNode -> value = value;
		this ->size = 1;
		this -> head = newNode;
		this -> tail = newNode;
		this -> tail -> next = nullptr;
	}
	List(void){
		this -> size = 0;
		this -> head = nullptr;
		this -> tail = nullptr;
	}

	void push_back(T value){
		Node* newNode = new Node();
		newNode -> value = value;
		if(size == 0){
			head = newNode;	
			tail = newNode;
		}else{
			tail -> next = newNode;
			tail = newNode;
			newNode -> next = nullptr;
		}
		++size;
	}
	void pop_back(void){
		if(size == 0){
			std::cout<<"listy datark e"<<std::endl;
			return;
		}
		Node* temp = head;
		for(int i = 0; i < size - 1;++i){
			temp = temp -> next;
		}
		Node* tmp = this -> tail;
		this -> tail = temp;
		delete tmp;
		tail -> next = nullptr;
		--size;
	}

	T& operator[](std::size_t index){
		int a = 0;
		int *b = &a;
		if(index < 0){
			std::cout<<"listum chka bacasakan index > 0"<<std::endl;
			return *b;
		}else if(index >= size){
			std::cout<<"indexy petq e poqr lini size ic"<<std::endl;
			return *b;
		}else if(index == 0 && size > 0){
			return head -> value;
		}else if(index == 0 && size == 0){
			std::cout<<"listy datark e"<<std::endl;
		}else{
			Node* temp = head;
			for(int i = 0; i < index;++i){
				temp = temp -> next;
			}
			return temp -> value;
		}
	}
	void insert_at_index(unsigned int index,T value){
		if(index < 0){
			std::cout<<"listum chka bacasakan index > 0"<<std::endl;
            return;
		} else if(index > size && index != 0){
			std::cout<<"indexy petq e poqr lini size ic"<<std::endl;
            return;
		} else if(index == size && index != 0){
			push_back(value);
			return;
		}
		Node* newNode = new Node();
		newNode -> value =  value;
		if(index == 0 && size == 0){
			this -> head = newNode;
			this -> tail = newNode;
			newNode -> next = nullptr;
		} else if(index == 0 && size > 0){
			this -> head = newNode;
			newNode -> next = nullptr;
		} else {
			Node* temp = this -> head;
			for(int i = 0; i < index - 1; ++i){
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
	        temp -> next = newNode;
			this -> tail = newNode;
		}
		++size;
	}
	void remove_at_index (unsigned int index) {
        if (index < 0) {
            std::cout<< "indexy bacasakan linel chi karox" <<std::endl;
            return;
        } else if (index >= size && size != 0) {
            std::cout<< "indexy chi karox mec kamhavasar linel size-ic" <<std::endl;
            return;
        } else if(size == 0) {
            std::cout<<"listy datark e "<<std::endl;
            return;
        }
		Node* temp = head;
		if(size == 1){
			delete head;
			this -> head = nullptr;
			this -> tail = nullptr;
			delete temp;
		} else if(size == 2 && index == 0){
			this -> head = this -> tail;
			delete temp;
		} else if(size == 2 && index == 1){
			temp = temp -> next;
			this -> tail = this -> head;
			delete temp;
		} else if(index == 0){
			head = temp -> next;
			delete temp;
		} else{
			for(int i = 0; i < index - 1;++i){
				temp = temp -> next;
			}
			Node* tmp = temp -> next;
			temp -> next = tmp -> next;
			delete tmp;
		}

		-- size;
	}
	int get_size(void){
		return this -> size;
	}
	void print(void){
		if(size == 0){
			std::cout<<"listy datark e"<<std::endl;
			std::cout<<"list size -> " << this -> size<<std::endl;
			return ;
		}
		Node* temp = head;
		std::cout<<"list size -> " << this -> size<<std::endl;
		if(temp -> next == nullptr){
			std::cout<<"list value"<<temp -> value <<std::endl;
		}else{
			for(int i = 0; i < size;++i){
				std::cout<<"list membr of -> "<< i << "("<<temp->value<<")";
				std::cout<<"\n";
				temp = temp -> next;
			}
		}
	}
	T get_max(void){
		int max = head -> value;
		Node* temp = head;
		for(int i = 0;i < size; ++i){
			if(temp -> value >= max){
				max = temp -> value;
			}
			temp = temp -> next;
		}
		return max;
	}
	T get_min(void){
		int min = head -> value;
        Node* temp = head;
        for(int i = 0;i < size; ++i){
            if(temp -> value <= min){
                min = temp -> value;
            }                
            temp = temp -> next;
        }
        return min;
	}
	~List(void){
		Node* temp = this -> head;
		for(int i = 0; i < size;++i){
			temp = temp -> next;
			delete head;
			head = temp;
		}
		head = nullptr;
		tail = nullptr;
	}
	void sort_nvazman(){
		T bufer;
		for(int i = 1; i < size;++i){
			Node* temp1 = head;
	        Node* temp2 = head -> next;
			for(int j = 1; j < size ; ++j){
				if(temp1 -> value < temp2 -> value){
					bufer = temp1 -> value;
					temp1 -> value = temp2 -> value;
					temp2 -> value = bufer;
				}
				temp1 = temp2;
				temp2 = temp2 -> next;
			}
		}
	}
	void sort_achman(){
        T bufer;
        for(int i = 1; i < size;++i){
            Node* temp1 = head;
            Node* temp2 = head -> next;
            for(int j = 1; j > size ; ++j){
                if(temp1 -> value < temp2 -> value){
                    bufer = temp1 -> value;
                    temp1 -> value = temp2 -> value;
                    temp2 -> value = bufer;
                }
                temp1 = temp2;
                temp2 = temp2 -> next;
            }
        }
    }
	void push_front(T value){
		Node* newNode = new Node();
		newNode -> value = value;
		newNode -> next = head;
		head = newNode;
		++size;
	}

	void pop_front(void){
		Node* temp = head;
		head = head -> next;
		delete temp;
		--size;
	}

	Node* reverse() {
		Node* newTail = this -> head;
		Node* phead = this -> head;
		while(head != nullptr) {
			Node* p = head->next;
			head-> next = phead;
			phead = head;
			head = p;
		}
		this -> head = phead;
		this -> tail = newTail;
	}

	void clear(void){
		while(this -> size != 0){
			pop_back();
		}
	}
};

int main(){
	List <int> list;
	list.push_back(10);	
	for(int i = 0; i < 10;++i){
		list.push_back(i);
	}
	
	list.print();
	list.reverse();
	list.print();
	
	return 0;
}