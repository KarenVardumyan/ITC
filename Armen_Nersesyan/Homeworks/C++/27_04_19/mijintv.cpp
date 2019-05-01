#include <iostream>

void maxmin(int* arr);

int main(){
	int arr[6]={0,0,0,0,0,0};
	for(int i = 0; i < 6;++i){
		std::cout<<"nermucel zangvaci "<<i+1<<" elementy->";
		std::cin>>arr[i];
	}		
	maxmin(arr);
	return 0;
}

void maxmin(int* arr){
	float m = 0;
	float max = arr[0];
	float min = arr[0];
	for(int i = 0;i < 6;++i){
		if(max < arr[i]){
			max = arr[i];
		}
		else{
			max = max;		
		}
		if(min > arr[i]){
			min = arr[i];
		}
		else{	
			min = min;
		}

	}
	m = (max+min)/2;
	std::cout<<"zangvaci mecaguyn ev poqraguyn arjeqneri mijin tvabanakann e -> "<<m<<std::endl;
}
