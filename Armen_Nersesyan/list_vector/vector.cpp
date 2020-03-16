#include<iostream>

class MyVector
{
    int size = 0;
    int* arr;
    int reserve_size = 0;

    public:
    MyVector(void){}
    MyVector(int constructor_size){
        arr = new int[constructor_size];
        size = constructor_size;
        for(int i = 0; i < size; ++i){
            arr[i] = 0;
        }
    }

    /*
     * Set the value the received value in the received index
     */
    void set_at_index(int index,int value){
        if(index >= this->size || index < 0){
            std::cout<<"no such index"<<std::endl;
            return;
        }

        for(int i = 0; ; i++){
            if(i == index){
                arr[index] = value;
                break;
            }
        }
    }

    int get_at_index(int index){
        if(index >= this->size || index < 0){
            std::cout<<"no such index"<<std::endl;
        }
        for(int i = 0; ;i++){
            if(i == index){
                return arr[index];
            }
        }
    }
    void push_back(int new_element){
        if(reserve_size == 0){
            reserve_size = 5;
            int* buffer = new int[size + reserve_size];
            for(int i = 0; i < size; ++i){
                buffer[i] = arr[i];
            }
            buffer[size] = new_element;
            delete [] arr;
            arr = buffer;
            buffer = NULL;
            ++size;
            --reserve_size;
        }else{
        arr[size] = new_element;
        ++size;
        --reserve_size;
        }
    }
    void pop_back(){
        if(size == 0){
            std::cout<<"The vector is empty"<<std::endl;
            return;
        }else{
        arr[size - 1] = 0;
        --size;
        }
    }
    void push_front(int new_element){
        if(reserve_size == 0){
            reserve_size = 5;
            int* buffer = new int[reserve_size];
            buffer[0] = new_element;
            for(int i = 0; i < size; ++i){
                buffer[i + 1] = arr[i];
            }
            delete [] arr;
            arr = buffer;
            buffer = NULL;
            ++size;
            --reserve_size;
        }else{
            ++size;
        for(int j = size - 1;j != 0;--j){
            arr[j] = arr[j-1];
        }
        arr[0] = new_element;
        --reserve_size;
        }
    }
    void pop_front(){
        if(size == 0){
            std::cout<<"The vector is empty"<<std::endl;
            return;
        }
        for(int i = 0; i < size; ++i){
            arr[i] = arr[i+1];
        }
        --size;
    }
    void insert_at_index(int index1,int index2,int newelement){
        if(size == 0){
            std::cout<<"The vector is empty"<<std::endl;
            return;
        }
        if(index1 < 0 || index2 < 0 || index1 >= size || index2 >= size){
            std::cout<<"No such index"<<std::endl;
            return;
        }
        if((index2 - index1) != 1 ){
            std::cout<<"ERROR at index"<<std::endl;
            return;
        }
        int* buffer = new int [size + 1];
        for(int i = 0; i <= index1;++i){
            buffer[i] = arr[i];
        }
        buffer[index1 + 1] = newelement;
        for(int i = index1 +2;i < size;++i){
            buffer[i] = arr[i - 1];
        }
        delete [] arr;
        arr = buffer;
        buffer = NULL;
        ++size;
    }
    void revers(void){
        if(size == 0){
            std::cout<<"The vector is empty"<<std::endl;
            return;
        }
        int* buffer = new int[size];
        for(int i = 0,j = size - 1; i < size, j != 0; ++i,--j){
            buffer[i] = arr[j];
        }
        delete []arr;
        arr = buffer;
        buffer = NULL;
    }
    void print(){
        if(size == 0){
            std::cout<<"The vector is empty"<<std::endl;
        }
        for (int i = 0; i < size; ++i){
            std::cout<<arr[i];
        }

    }
    int get_size(void){
        return this->size;
    }
    ~MyVector(void){
        delete []arr;
    }
};


int main(){


    return 0;
}