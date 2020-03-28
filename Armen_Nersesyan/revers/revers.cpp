#include <iostream>
#include <cstdlib>
#include<cstring>

void revers(void* array,int size,int byte);/*reversed using a single variable of int type*/
int main() {
  int size = 0;
  std::cout<<"Input size array"<<std::endl;
  std::cin>>size;
  std::cout<<"array size = "<<size<<" item type int. Input numbers and click enter"<<std::endl;
  int* arr = new int[size];
  for (int i = 0; i < size; i++){
    std::cin>>arr[i];
  }
  revers(arr,size,sizeof(arr[0]));
  for (int i = 0; i < size; i++)
  {
    std::cout<<arr[i];
  }
  return 0;
}

void revers(void* array,int size,int byte){
  void* temp = (void*)malloc(4);
  for(int i = 0; i < size/2; i++){
      memmove(temp,array + (size - i -1) * byte,byte);
      memmove(array + (size -1 - i) * byte,array + i * byte,byte);
      memmove(array + i * byte,temp,byte);
  }
  free(temp);
}
