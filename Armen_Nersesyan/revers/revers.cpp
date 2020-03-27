#include <iostream>

void revers(int* array,int size);/*reversed using a single variable of int type*/
void print(int* array,int size);
int main() {
  int size;
  std::cin>>size;
  std::cout<<"array size = "<<size<<" item type int. Input numbers and click enter"<<std::endl;
  int *array = new int[size];
  for(int i = 0; i < size; ++i){
    std::cin>>array[i];
  }
  print(array,size);
  revers(array,size);
  print(array,size);
  return 0;
}

void revers(int* array,int size){
  int temp = 0;
  for(int i = 0, j = size - 1; i < j; ++i,--j){
    array[i] = array[i] + array[j];
    array[j] = array[i] - array[j];
    array[i] -= array[j];
  }
}
void print(int* array,int size){
  std::cout<<"\n";
  for(int i = 0; i < size; ++i){
    std::cout<<array[i]<<" ";
  }
}

