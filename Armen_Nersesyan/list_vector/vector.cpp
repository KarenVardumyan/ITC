#include<iostream>

class Myvector
{
    int size = 0;
    int* arr;
    int rezerv_size = 0;

    public:
    Myvector(void){}
    Myvector(int constructor_size){
        arr = new int[constructor_size];
        size = constructor_size;
        for(int i = 0; i < size; ++i){
            arr[i] = 0;
        }
    }
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
        if(rezerv_size == 0){
            rezerv_size = 5;
            int* bufer = new int[size + rezerv_size];
            for(int i = 0; i < size; ++i){
                bufer[i] = arr[i];
            }
            bufer[size] = new_element;
            delete [] arr;
            arr = bufer;
            bufer = NULL;
            ++size;
            --rezerv_size;
        }else{
        arr[size] = new_element;
        ++size;
        --rezerv_size;
        }
    }
    void pop_back(){
        if(size == 0){
            std::cout<<"vector empty"<<std::endl;
            return;
        }else{
        arr[size - 1] = 0;
        --size;
        }
    }
    void push_front(int new_element){
        if(rezerv_size == 0){
            rezerv_size = 5;
            int* bufer = new int[rezerv_size];
            bufer[0] = new_element;
            for(int i = 0; i < size; ++i){
                bufer[i + 1] = arr[i];
            }
            delete [] arr;
            arr = bufer;
            bufer = NULL;
            ++size;
            --rezerv_size;
        }else{
            ++size;
        for(int j = size - 1;j != 0;--j){
            arr[j] = arr[j-1];
        }
        arr[0] = new_element;
        --rezerv_size;
        }
    }
    void pop_front(){
        if(size == 0){
            std::cout<<"vector empty"<<std::endl;
            return;
        }
        for(int i = 0; i < size; ++i){
            arr[i] = arr[i+1];
        }
        --size;
    }
    void insert_at_index(int index1,int index2,int newelement){
        if(size == 0){
            std::cout<<"vecor empty"<<std::endl;
            return;
        }
        if(index1 < 0 || index2 < 0 || index1 >= size || index2 >= size){
            std::cout<<"no such index"<<std::endl;
            return;
        }
        if((index2 - index1) != 1 ){
            std::cout<<"EROR at index"<<std::endl;
            return;
        }
        int* bufer = new int [size + 1];
        for(int i = 0; i <= index1;++i){
            bufer[i] = arr[i];
        }
        bufer[index1 + 1] = newelement;
        for(int i = index1 +2;i < size;++i){
            bufer[i] = arr[i - 1];
        }
        delete [] arr;
        arr = bufer;
        bufer = NULL;
        ++size;
    }
    void revers(void){
        if(size == 0){
            std::cout<<"vector empty"<<std::endl;
            return;
        }
        int* bufer = new int[size];
        for(int i = 0,j = size - 1; i < size, j != 0; ++i,--j){
            bufer[i] = arr[j];
        }
        delete []arr;
        arr = bufer;
        bufer = NULL;
    }
    void print(){
        if(size == 0){
            std::cout<<"Vector empty"<<std::endl;
        }
        for (int i = 0; i < size; ++i){
            std::cout<<arr[i];
        }

    }
    int get_size(void){
        return this->size;
    }
    ~Myvector(void){
        delete []arr;
    }
};


int main(){


    return 0;
}