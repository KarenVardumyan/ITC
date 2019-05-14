#include<iostream>

class Vector
{	
	int itssize;
	int* itsarr;
	public:
	Vector(void){
	}	
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
	void pop_back(void){
		std::cout<<"kanchvec pop_back funkcian myvector obyekti vra"<<std::endl;
		int* temp = new int[itssize - 1];
		for(int i = 0; i < itssize - 1;++i){
			temp[i] = itsarr[i];
		}
		delete []itsarr;
		itsarr = temp;
		temp = NULL;
		--itssize;
	}
	void push_back(int newelement){
		std::cout<<"kanchvec push_back funkcian myvector obyekti vra"<<std::endl;
		int* temp = new int[itssize + 1];
		for(int i = 0; i < itssize +1; ++i){
			temp[i] = itsarr[i];
		}
		temp[itssize] = newelement;
		delete [] itsarr;
		itsarr = temp;
   		temp = NULL;
	 	++itssize;	
	}
	void print(void){
		std::cout<<"print myvector"<<std::endl;
		for(int i = 0; i < itssize;++i){
			std::cout<<itsarr[i]<<std::endl;
		}
	}
	int get_size(void){
		return itssize;
	}

	~Vector(void){
		std::cout<<"desktruktori kanch delete masiv"<<std::endl;
		delete [] itsarr;
	}

};


int main(){
	Vector myvector(5);
	myvector.print();
	for(int i = 0; i < myvector.get_size();++i){
		myvector.set_atindex(i,i * 3);
	}
	//myvector.set_atindex(0,10);
	myvector.print();
	std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	myvector.pop_back();
	myvector.print();
	std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	myvector.push_back(50);
	myvector.print();
	std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	return 0;
}
