#include<iostream>
#include<fstream>
#include<streambuf>

class Myjson
{
	int itsage;
	std::string itsname;
	std::string itsjob;
	public:
	~Myjson(){};

	 std::string get_name (void) const {
        return this -> itsname;
    }

    void set_name (std::string name) {
        this -> itsname = name;
    }
    
    int get_age (int age) const {
        return this -> itsage;
    }

    void set_age (int age){
        this -> itsage = age;
    }

    std::string get_job (std::string job) const{
        return this -> itsjob;
    }
	void set_job(std::string job){
		this -> itsjob = job;
	}
	Myjson(void){
		this-> itsname = "Name";
		this-> itsage = 195;
		this-> itsjob = "Job";
	}
	Myjson(std::string name,int age,std::string job){
		this-> itsname = name;
		this-> itsage = age;
		this-> itsjob = job;
	}
	void print(void) const {
		std::cout<<"name "<<this-> itsname<<std::endl;
		std::cout<<"age "<<this-> itsage<<std::endl;
		std::cout<<"job "<<this-> itsjob<<std::endl;
	}
};
void jsonobject_classobject(std::string* objectarr){
     for(int i = 0; i < 3;++i){
		for(int j = 0; j < objectarr[i].length();++j){

		}
    }
}

std::string json_object(std::string json){
	std::string objectjson = "";
	for(int i = 0; i < json.length();++i){
		if(json[i] == '{'){
			for(int j = i + 1; j < json.length();++j){
				if(json[j] == '}'){
					return objectjson;
				}else{
					objectjson = objectjson + json[j];
				}
			}
		}
    }
}
void delete_object(std::string& json){
    std::string newjson = "[";
    for(int i = 1; i < json.length();++i){
        if(json[i] == '}'){
      		for(int j = i + 2; j < json.length(); ++j){
				newjson = newjson + json[j];
			}
			json = newjson;
			return;
		}
	}
}



int main(){
	std::ifstream t("myjson.json");
    std::string json((std::istreambuf_iterator<char>(t)),
    std::istreambuf_iterator<char>());
	for(int i = 0; i < json.length();++i){
		std::cout<<json[i];
	}
	std::string objectarr[3];
	for(int i = 0; i < 3;++i){
		objectarr[i] = json_object(json);
		delete_object(json);
	}
	//for(int i = 0; i < 3;++i){
      //  std::cout<<objectarr[i]<<std::endl;
    //}
	Myjson object[3];
	jsonobject_classobject(objectarr);

	return 0;
}
