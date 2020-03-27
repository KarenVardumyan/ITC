#include <iostream>

void revers(int* array);/*reversed using a single variable of int type*/
void revers1(int* array);/*reversed using one temporary array*/
void print(int* array);
const int SIZE = 5;
int main() {
  std::cout<<"array size = "<<SIZE<<" item type int. Input numbers and click enter"<<std::endl;
  int array[SIZE];
  for(int i = 0; i < SIZE; ++i){
    std::cin>>array[i];
  }
  print(array);
  revers(array);
  print(array);
  revers1(array);
  print(array);
  return 0;
}

void revers(int* array){
  int temp = 0;
  for(int i = 0, j = SIZE - 1; i < j; ++i,--j){
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
void revers1(int* array){
  int *temp = new int[SIZE];
  for (int i = 0; i < SIZE; ++i){
    temp[i] = array[i];
  }
  for (int i = 0; i < SIZE; ++i){
    array[i] = temp[SIZE - 1 - i];
  }
  delete [] temp;

}
void print(int* array){
  std::cout<<"\n";
  for(int i = 0; i < SIZE; ++i){
    std::cout<<array[i]<<" ";
  }
}

