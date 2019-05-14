#include<iostream>
#include<string>
#include<vector>
void sortmystring(std::string &mystring);

int main(){
	
	std::string mystring;
	std::cout<<"cin text"<<std::endl;
	std::getline(std::cin,mystring);

	sortmystring(mystring);

	return 0;
}

void sortmystring(std::string &mystring){
	std::vector<char> myvector(0);
	for(int i = 0; i < mystring.length();++i){
		if(((int)mystring[i] >= 65 && (int)mystring[i] <= 90) || ((int)mystring[i] >= 97 && (int)mystring[i] <= 122)){
			myvector.push_back(mystring[i]);
		}	
	}
	std::cout << "my  new text" << std::endl;
    for (int i = 0; i < sizeof(myvector); i++) {
    	std::cout << myvector[i];
    }	
	std::cout<<"\n";
}

