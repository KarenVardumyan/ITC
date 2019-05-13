#include<iostream>

class Vector
{	
	int itssize;
	public:
	int* itsarr;

	Vector(int chap){
		std::cout<<"konstruktor"<<std::endl;
		itsarr = new int[chap];
		for(int i = 0; i < chap;++i){
			itsarr[i] = 0;
		}
		itssize = chap;
	}
	void set_atindex(int index,int value){
		std::cout<<"set_atindex funkciayi kanch"<<std::endl;
		itsarr[index] = value;
	}

	void print(void){
		std::cout<<"print myvector"<<std::endl;
		for(int i = 0; i < itssize;++i){
			std::cout<<itsarr[i]<<std::endl;
		}
	}

	~Vector(void){
		std::cout<<"desktruktori kanch delete masiv"<<std::endl;
		delete [] itsarr;
	}

};


int main(){
	Vector myvector(5);
	myvector.print();
	myvector.set_atindex(0,10);
	myvector.print();
	return 0;
}
