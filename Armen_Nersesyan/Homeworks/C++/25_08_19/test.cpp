#include<iostream>

bool search(int* arr,char simvol);
void kesh(int* arr,char* arr1);
int main(){
	
	int arr[250];
	char arr1[5] = {' ','@','%','*','('};
	for(int i = 0; i < 250;++i){
		arr[i] = 0;
	}
	
	kesh(arr,arr1);

	if(!search(arr,'(')){
		std::cout<<"false"<<std::endl;
	}else{
		std::cout<<"true"<<std::endl;
	}

	return 0;
}

bool search(int* arr,char simvol){
	if(arr[(int)simvol] == simvol){
		return true;
	}else{
		return false;
	}
}

void kesh(int* arr,char* arr1){
	for(int i = 0; i < 5;++i){
		arr[(int)arr1[i]] = arr1[i];
	}
}

