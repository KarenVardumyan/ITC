
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

class Person{
        int age;
        std::string name;
        std::string job;

    public:
    ~Person(){
        
    }
    std::string GetName(void) const {
        return name;
    }
    void SetName(std::string name) {
        this -> name = name;
    }
    std::string GetJob(void) const {
        return job;
    }
    void SetJob(std::string job) {
        this -> job = job;
    }
    int GetAge(void) const {
        return age;
    }
    void SetAge(int age) {
        this -> age = age;
    }
    void print(void) const {
		std::cout<<"              Name: "<< this -> name << "\n";
		std::cout<<"              Age: "<< this -> age << "\n";
		std::cout<<"              Job: "<< this -> job << "\n\n";
	}
};

void InvalidCharDelete(std::string& str){
    
	std::string CleanStr = "";
	for(int i = 0; i < str.length();++i){
		if(str[i] != '"' && str[i] != ' ' && str[i] != '\n' && str[i] != '{' && str[i] != '[' && str[i] != '}' && str[i] != '\t'){
		CleanStr += str[i];
		}
	}
	str = CleanStr;
}

void CreateObjectsByJson(std::string str,Person* person,int iter,int i,int j,int x,int SIZE){
    if(x == SIZE * 3){
        return;
    }
    std::string Key = "";
    std::string Value = "";
    for(i; ;++i){
        if(str[i] == ':') break;
        Key += str[i]; 
    }
    for(j = i + 1; ;++j){
        if(str[j] == ',' || str[j] == ']') break;
        Value += str[j]; 
    }
    switch(Key[0]){
    	case 'n':
            person[iter].SetName(Value);
            break;
        case 'a':
            person[iter].SetAge(std::stoi(Value));
            break;
        case 'j':
            person[iter].SetJob(Value);
            iter++;
            break;
    }
    CreateObjectsByJson(str,person,iter,j + 1,j,x + 1,SIZE);
}

int main(){
    int SIZE = 0;
    std::ifstream t("text.json");
    std::string str((std::istreambuf_iterator<char>(t)),
    std::istreambuf_iterator<char>());
    
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == '}'){
            SIZE++;
        }
    }
    Person* person = new Person[SIZE];

    InvalidCharDelete(str);
    CreateObjectsByJson(str,person,0,0,0,0,SIZE);

    for(int i = 0; i < SIZE; ++i){
        std::cout <<"_______________Person  #" << i << "______________\n\n";
		person[i].print();
	}
	delete [] person;
return 0;
}
