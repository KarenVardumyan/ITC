#include<iostream>
void print(int *arr);
void maxarr(int* arr);

int main(){
	int arr[10];
	for(int i = 0; i < 10; ++i){
		std::cout<<"arr["<<i<<"] ->  ";
		std::cin>>arr[i];
	}
	maxarr(arr);
	return 0;
}

void maxarr(int* arr){
	int max = 0;
	int temp = 0;
	int j = 1;
	for(j; j <= 10; ++j){
		for(int i = 0 ; i < 10; ++i){
    		if(arr[i] >= max){
			max = arr[i];
			temp = i;
			}else if(arr[i] < max){
			max = max;
			}
		}
	std::cout<<"max -> "<<max<<std::endl;
	std::cout<<"zangvaci max tivn arr["<<temp<<"] elementn e"<<std::endl;
	std::cout<<"###############  cikl "<<j<<" ##################"<<std::endl;
	std::cout<<"sharunakelu hamar sexmel -> Enter"<<std::endl;
	std::cin.ignore();
	arr[temp] = 0;
	print(arr);
	std::cout<<"\n";
	max = 0;
	}
}
void print(int *arr){

	for(int i = 0; i < 10; ++i){
        std::cout<<"arr["<<i<<"] -> "<<arr[i]<<std::endl;
    }
}

