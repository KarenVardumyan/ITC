#include<iostream>

void sortaray(int* arr,int size, char nshan);
void printarr(int* arr, int size);

int main(){

	int arr[5];
    int size = sizeof(arr)/sizeof(int);
	char nshan = ' ';
	for(int i = 0; i < 5; ++i){
		std::cout<<"arr["<<i<<"] -> ";
		std::cin>>arr[i];
	}
	std::cout<<"masivy achman kargov dasavorelu hmar mutqagreq (+) nshany, nvazman hamar (-) nshany"<<std::endl;
	std::cin>>nshan;

	sortaray(arr,size,nshan);

	return 0;
}
void sortaray(int* arr,int size,char nshan){
	int bufer = 0;
	if(nshan == '-'){
		for(int i = 0; i < size; ++i){
			for(int j = i+1; j < size;++j){
				if(arr[i] < arr[j]){
				bufer = arr[j];
				arr[j] = arr[i];
				arr[i] = bufer;
				}
			}
		}
	}else if(nshan == '+'){
		for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size;++j){
                if(arr[i] > arr[j]){
                bufer = arr[j];
                arr[j] = arr[i];
                arr[i] = bufer;
                }
            }
        }
	}else {
		std::cout<<"mutqagrvac e sxal nshan"<<std::endl;
	}
	printarr(arr,size);
}
void printarr(int* arr,int size){
	for(int i = 0; i < size; ++i){
		std::cout<<"arr["<<i<<"] -> "<<arr[i]<<std::endl;
	}
}
