#include<iostream>

template <typename T>

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

	T get_at_index(int index){
		if(index < 0){
			std::cout<<"listum chka bacasakan index > 0"<<std::endl;
			return 0;
		}else if(index >= size){
			std::cout<<"indexy petq e poqr lini size ic"<<std::endl;
			return 0;
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
	/*void insert_at_index(int index,T value){
		if(index < 0){
			std::cout<<"listum chka bacasakan index > 0"<<std::endl;
            return;
		}else if(index > size && index != 0){
			std::cout<<"indexy petq e poqr lini size ic"<<std::endl;
            return;
		}else if(index == size && index != 0){
			push_back(value);
			return;
		}
		Node* newNode = new Node();
		newNode -> value =  value;
		if(index == 0 && size == 0){
			this -> head = newNode;
			this -> tail = newNode;
			newNode -> next = nullptr;
		}else if(index == 0 && size != 0){
			this -> head = newNode;
			nowNode -> next = nullptr;
		}else{
			Node* temp = this -> head;
			for(int i = 0; i < index - 1; ++i){
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
	        temp -> next = newNode;
			this -> tail = newNode;
		}

		++size;
	}*/
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

};

int main(){
	List <int> list;
	for(int i = 0; i < 5;++i){
		list.push_back(i);
	}

	list.print();

	return 0;
}
