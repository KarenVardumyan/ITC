#include<iostream>
#include<string>
#include<vector>

void pakagcer(std::string &mystring);

int main(){

	std::string mystring;
	std::cout<<"nermucel text"<<std::endl;			//cragiry stugelu e textum exac pakagceri sxal kam chisht bacvel ev pakvely
	std::getline(std::cin,mystring);
	
	pakagcer(mystring);

	return 0;
}

void pakagcer(std::string &mystring){
	std::vector<char> myvector(0);
	int counter = 0;
	int temp = 0;
	int bufer = 0;
	for(int i = 0; i < mystring.length(); ++i){
		if(mystring[i] == ']' || mystring[i] == ')' || mystring[i] == '}' || mystring[i] == '{' || mystring[i] == '[' || mystring[i] == '(')
		++counter;
			if(mystring[i] == ']' && counter == 1 || mystring[i] == ')' && counter == 1 || mystring[i] == '}' && counter == 1){
				std::cout<<"texty chi karox sksvel pakvox pakagcov"<<std::endl;
				return;
			}
	}
	for(int i = 0; i < mystring.length(); ++i){
		if(mystring[i] == '(' || mystring[i] == '[' || mystring[i] == '{'){
			myvector.push_back(mystring[i]);
			++temp;
		}else if((mystring[i] == ')' && myvector[myvector.size() - 1] == '(') || (mystring[i] == ']' && myvector[myvector.size() - 1] == '[') || (mystring[i] == '}' && myvector[myvector.size() - 1] == '{')){
			myvector.pop_back();
			++temp;
		}else if((mystring[i] == ')' && myvector[myvector.size() - 1] != '(') || (mystring[i] == ']' && myvector[myvector.size() - 1] != '[') || (mystring[i] == '}' && myvector[myvector.size() - 1] != '{')){
			std::cout<<i+1<<"-rd indexsum ka pakagci sxal"<<std::endl;
        	return;
		}
	}
	if(myvector.empty() == 0){
		std::cout<<"ka pakagci sxal "<<std::endl;
		for(int i = 0; i < mystring.length(); ++i){
			if(mystring[i] == ')' || mystring[i] == '}' || mystring[i] == '{' || mystring[i] == '[' || mystring[i] == '(' || mystring[i] == ']'){
				++bufer;
				if(bufer == temp){
					std::cout<<i+1<<"-rd indexsum";
					return;
				}
			}
		}
	}else{
		std::cout<<"pakagcery chisht en drvac"<<std::endl;
	}

}
