#include<iostream>

class Vector
{	
	int itssize;
	int* itsarr;
	int rezerv_size = 0;
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
	    //std::cout<<"set_atindex funkciayi kanch"<<std::endl;
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
	int get_atindex(int index){
		if(index > itssize){
			std::cout<<index<<"-rd indexy durs e masivic"<<std::endl;
			return 444;
		}
		return itsarr[index];
	}
	void push_back(int newelement){
		std::cout<<"kanchvec push_back funkcian myvector obyekti vra"<<std::endl;
		if(rezerv_size = 0){
			rezerv_size  = 5;
			int* temp = new int[itssize + rezerv_size];
			for(int i = 0; i < itssize + 1;++i){
				temp[i] = itsarr[i];
			}
			temp[itssize] = newelement;
			for(int i = itssize + 1; i < itssize+ rezerv_size;++i){
				temp[i] = 0;
			}
			delete [] itsarr;
			itsarr = temp;
			++itssize;
			--rezerv_size;
		}else{
		itsarr[itssize] = newelement;
	 	++itssize;	
		--rezerv_size;
		}
	}
	void swap(int index1, int index2){
		if(index1 > itssize || index2 > itssize){
            std::cout<<" indexy durs e masivic"<<std::endl;
            return ;
        }

		int temp = 0;
		temp =itsarr[index1];
		itsarr[index1] = itsarr[index2];
		itsarr[index2] = temp;
	}
	void revers(void){
		int* temp = new int[itssize];
		for(int i = 0,j = itssize -1;i < itssize, j != 0;++i,--j){
			temp[i] = itsarr[j];
		}
		delete [] itsarr;
		itsarr = temp;
		temp = NULL;

	}
	void insert_atindex(int index1,int index2,int newelement){
		int* temp = new int[itssize + 1];
		for(int i = 0; i <= index1; ++i){
			temp[i] = itsarr[i];
		}
		temp[index2] = newelement;
		index2 = index2 + 1;
		for(int i = index1 + 1; i < itssize ; ++i){
			temp[i+1] = itsarr[i];
		}
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
	void sort_nvazman(void){
		int max = 0;
		for(int i = 0 ; i < itssize ; ++i){
            for(int j = i + 1 ; j < itssize; ++j){
                if(itsarr[i] < itsarr[j]){
                    max = itsarr[j];
                    itsarr[j] = itsarr[i];
                    itsarr[i] = max;
                }
            }
        }

	}
	void front_push(int value){
		int* temp = new int[itssize + 1];
		temp[0] = value;
		for(int i = 0, j = 1; i < itssize,j < itssize + 1;++i,++j ){
			temp[j] = itsarr[i];
		}
		delete [] itsarr;
		itsarr = temp;
		temp = NULL;
		++itssize;
	
	}
	void front_pop(){
		int* temp = new int[itssize - 1];
		for(int i = 0,j = 1; i < itssize - 1,j < itssize;++i,++j){
			temp[i] = itsarr[j];
		}
		delete [] itsarr;
		itsarr = temp;
		temp = NULL;
		--itssize;
	}
	int vector_max(){
	int max = itsarr[0];
		for(int i = 1; i < itssize;++i){
			if(max < itsarr[i]){
				max = itsarr[i];
			}
		}
		return max;
	}
	void clear(){
		for(int i = 0; i < itssize;++i){
			itsarr[i] = 0;
		}
	}
	~Vector(void){
		std::cout<<"desktruktori kanch delete masiv"<<std::endl;
		delete [] itsarr;
	}

};


int main(){
	Vector myvector(5);
	for(int i = 0; i < myvector.get_size();++i){
		myvector.set_atindex(i,i * 3);
	}
	//myvector.set_atindex(0,10);
	myvector.print();
	std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	//myvector.pop_back();
	//std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	myvector.push_back(50);
	//std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	//myvector.insert_atindex(1,2,7777777);
    //std::cout<<"size myvector-> "<<myvector.get_size()<<std::endl;
	//std::cout<<myvector.get_atindex(15)<<std::endl;
	//myvector.swap(2,3);
	//myvector.revers();
	//myvector.sort_nvazman();
	//myvector.front_push(20);
	//myvector.front_pop();
	//myvector.clear();
	myvector.print();
	//std::cout<<myvector.vector_max()<<std::endl;
	return 0;
}
