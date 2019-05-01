#include<iostream>

void swap(int& a,int& b);

int main(){
	int a = 10;
	int b = 0;
	std::cout<<"a = "<<a<<std::endl;
	std::cout<<"b = "<<b<<std::endl;
	swap(a,b);
	std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;

	return 0;
}

void swap(int& a,int& b){
	int bufer = a;
	a = b;
	b = bufer;
}

