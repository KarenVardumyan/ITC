class Vector {
    int* array;
    int size;
    int capacity;
	    
    public:
    Vector() {
    	array = new int[0];
   		size = 0;
   		capacity = 0;
    }
    Vector(int size) {    
        this -> capacity = size;
    	array = new int[capacity];
    	this -> size = size;

    }
    ~Vector() {
        delete [] array;
        array = NULL;
    }

    void sort(int UpOrDown){
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


    void push_back(int value){
        size++;
        if(size == 1){
            capacity = 2;
            array[size - 1] = value;
        } 
        else if(size != 1 && size > capacity){
            capacity = capacity * 2;
            int* newarray = new int[capacity];
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
    
    void push_front(int value){
        size++;
        if(size == 1){
            capacity = 2;
            array[0] = value;
        } 
        else if(size != 1){
            if(size > capacity){
                capacity = capacity * 2;
            }
            int* newarray = new int[capacity];
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
        int* newarray = new int[size--];
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
        int* newarray = new int[capacity];
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
    
    int get_max(){
        int max = array[0];
        for(int i = 0; i < size; ++i){
            if(array[i] > max){
                max = array[i];
            }
        }
        return max;
    }
    
    int get_min(){
        int min = array[0];
        for(int i = 0; i < size; ++i){
            if(array[i] < min){
                min = array[i];
            }
        }
        return min;
    }
    
    int get_at_index(int index){
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!get_at_index(ERROR)...\n";
            return 0;
        }
        return array[index];
    }
    
    void insert_at_index(int index,int value){
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!insert_at_index(ERROR)...\n";
            return;
        }
        size++;
        int* newarray = new int[capacity];
        for(int i = 0; ; ++i){
            if(i == index){
                break;
            }
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
    
    void set_at_index(int index,int value) {
        if(index < 0 || index > size){
            std::cout << "Out of vector size...!set_at_index(ERROR)...\n";
            return;
        }
        array[index] = value;
    }
    
	int get_size() {
		return this -> size;
	}
	
	int get_capacity(){
        return this -> capacity;
    }
    
    void clear(){
        delete [] array;
        array = NULL;
    	array = new int[0];
   		size = 0;
   		capacity = 0;
    }
    
	void print() {
		for(int i = 0; i < size; ++i) {
			std::cout << "vector[" << i << "] = " << array[i] << std::endl;
		}
	}
};
