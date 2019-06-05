#include <iostream>

template<typename T>
class Vector{
    
    T* array;
    int size;
    int capacity;
	    
    public:
    Vector(){
    	array = new T[0];
   		size = 0;
   		capacity = 0;
    }
    
    Vector(int size){    
        this -> capacity = size;
        this -> size = size;
    	array = new T[capacity];
    }
    
    Vector(int size,T value){
        this -> capacity = size;
        this -> size = size;
        array = new T[capacity];
        for(int i = 0; i < size; ++i){
            array[i] = value;
        }
    }
    
    ~Vector(){
        delete [] array;
        array = NULL;
    }
    
    void shrink_to_fit(){
        if(size <= 0){
            std::cout << "The vector is empty...!shrink_to_fit(ERROR)...\n";
            return;
        }
        T* newarray = new T[size];
        for(int i = 0; i < size; ++i){
            newarray[i] = array[i];
        }
        delete [] array;
        array = newarray;
        newarray = NULL;
        capacity = size;
    }
    
    void swap(int index1,int index2){
        if((index1 < 0 || index1 > size) || (index2 < 0 || index2 > size)){
            std::cout << "Out of vector size...!swap(ERROR)...#1\n";
            return;
        }
        T tmp = array[index1];
        array[index1] = array[index2];
        array[index2] = tmp;
        tmp = 0;
    }
    
    void swap(Vector &vector,int index1,int index2){
        if((index1 < 0 || index1 > vector.size) || (index2 < 0 || index2 > size)){
            std::cout << "Out of vector size...!swap(ERROR)...#2\n";
            return;
        }
        T tmp = vector.array[index2];
        vector.array[index2] = array[index1];
        array[index1] = tmp;
        tmp = 0;
    }
    
    void swap(Vector &vector){
        int tmpSize = size;
        int tmpCapacity = capacity;
        T* tmp = new T[size];
        for(int i = 0; i < size; ++i){
            tmp[i] = array[i];
        }
        delete [] array;
        array = vector.array;
        size = vector.size;
        capacity = vector.capacity;
        vector.array = tmp;
        vector.size = tmpSize;
        vector.capacity = tmpCapacity;
        tmp = NULL;
        tmpSize = 0;
        tmpCapacity = 0;
    }
    
    void sort(int UpOrDown) const{
        if(size <= 0){
            std::cout << "The vector is empty...!sort(ERROR)...\n";
            return;
        }
        int tmp;
        if(UpOrDown == 0){
            for(int i = 0; i < size - 1; ++i){            
                for(int j = 0; j < size - 1; ++j){     
                    if (array[j + 1] < array[j]) {
                        tmp = array[j + 1]; 
                        array[j + 1] = array[j]; 
                        array[j] = tmp;
                    }
                }
            }
        }   
        else   
        {
            for(int i = 0; i < size - 1; ++i){            
                for(int j = 0; j < size - 1; ++j){     
                    if (array[j + 1] > array[j]) {
                        tmp = array[j + 1]; 
                        array[j + 1] = array[j]; 
                        array[j] = tmp;
                    }
                }
            } 
        }
    }


    void push_back(T value){
        size++;
        if(size == 1){
            capacity = 2;
            array[size - 1] = value;
        } 
        else if(size != 1 && size > capacity){
            capacity = capacity * 2;
            T* newarray = new T[capacity];
            newarray[size - 1] = value;
            for(int i = 0; i <= size - 2; ++i){
                newarray[i] = array[i];
            }
            delete [] array;
            array = newarray;
            newarray = NULL;
        }else {
                array[size - 1] = value;
            }
    }
    
    void push_front(T value){
        size++;
        if(size == 1){
            capacity = 2;
            array[0] = value;
        } 
        else if(size != 1){
            if(size > capacity){
                capacity = capacity * 2;
            }
            T* newarray = new T[capacity];
            newarray[0] = value;
            for(int i = 1; i <= size - 1; ++i){
                newarray[i] = array[i - 1];
            }
            delete [] array;
            array = newarray;
            newarray = NULL;
        }
    }    
    
    void pop_back(){
        if(size <= 0){
            std::cout << "The vector is empty...!pop_back(ERROR)...\n";
            return;
        }
        array[--size] = 0;
    }
    
    void pop_front(){
        if(size <= 0){
            std::cout << "The vector is empty...!pop_front(ERROR)...\n";
            return;
        }
        T* newarray = new T[size--];
        for(int i = 0; i < size; ++i){
            newarray[i] = array[i + 1];
        }
        delete [] array;
        array = newarray;
        newarray = NULL;
    }
    
    void pop_at_index(int index){
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!pop_at_index(ERROR)...\n";
            return;
        }
        size--;
        T* newarray = new T[capacity];
        for(int i = 0; ; ++i){
            if(i == index){
                break;
            }
            newarray[i] = array[i];
        }
        for(int i = index; i < size; ++i){
            newarray[i] = array[i + 1];
        }
        delete [] array;
        array = newarray;
        newarray = NULL;
    }
    
    T get_max() const{
        T max = array[0];
        for(int i = 0; i < size; ++i){
            if(array[i] > max){
                max = array[i];
            }
        }
        return max;
    }
    
    T get_min() const{
        T min = array[0];
        for(int i = 0; i < size; ++i){
            if(array[i] < min){
                min = array[i];
            }
        }
        return min;
    }
    
    T get_at_index(int index) const{
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!get_at_index(ERROR)...\n";
            return 0;
        }
        return array[index];
    }
    
    void insert_at_index(int index,T value){
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!insert_at_index(ERROR)...\n";
            return;
        }
        size++;
        T* newarray = new T[capacity];
        for(int i = 0; i <= index; ++i){
            newarray[i] = array[i];
        }
        newarray[index] = value;
        for(int i = index + 1; i < size; ++i){
            newarray[i] = array[i - 1];
        }
        delete [] array;
        array = newarray;
        newarray = NULL;
    }
    
    void set_at_index(int index,T value) {
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!set_at_index(ERROR)...\n";
            return;
        }
        array[index] = value;
    }
    
	int get_size() const{
		return this -> size;
	}
	
	int get_capacity() const{
        return this -> capacity;
    }
    
    void clear(){
        if(size <= 0){
            std::cout << "The vector is empty...!clear(ERROR)...\n";
            return;
        }
        delete [] array;
        array = NULL;
    	array = new T[0];
   		size = 0;
   		capacity = 0;
    }
    
	void print() const{
	    if(size <= 0){
            std::cout << "The vector is empty...!\n";
            return;
        }
		for(int i = 0; i < size; ++i) {
			std::cout << "vector[" << i << "] = " << array[i] << std::endl;
		}
		std::cout << std::endl;
	}
};
