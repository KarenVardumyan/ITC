#include<iostream>
#include<string>
#include<fstream>

void fillupjson(void);

int main(){

	fillupjson();
	return 0;
}

void fillupjson(void){
	std::string stringjson = "[";
	std::string name = "", age = "", job = "";
	char bul = ' ';
	int count = 1;
	for(int i = 1; ; ++i){
		std::cout<<"\t\tobject "<<count<<std::endl;
		std::cout<<"\"name\" : ";
		std::cin>>name;
		stringjson = stringjson + "\n\t{\n\t\t\"name\":\"" + name + "\",";
		std::cout<<"\"age\" : ";
		std::cin>>age;
        stringjson = stringjson + "\n\t\t\"age\":\"" + age + "\",";
		std::cout<<"\"job\" : ";
		std::cin>>job;
        stringjson = stringjson + "\n\t\t\"job\":\"" + job + "\"\n\t}\n";
		std::cout<<"\t\t 0(break) else(countinue)"<<std::endl;
		std::cin>>bul;
		if(bul == '0'){
			break;
		}
		++count;
		name = "";
   		age  = "";
		job  = "";
	}
	stringjson = stringjson + "\n]";
	std::ofstream object("json.json");
	object << stringjson;
	object.close();
}
