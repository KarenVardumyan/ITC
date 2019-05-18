#include<iostream>
#include<fstream>
#include<streambuf>

class Myjson {
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
    
    int get_age (void) {
        return this -> itsage;
    }

    void set_age (int age){
        this -> itsage = age;
    }

    std::string get_job (void) {
        return this -> itsjob;
    }
	void set_job(std::string job){
		this -> itsjob = job;
	}
	Myjson(void){
		this -> itsname = "Name";
		this -> itsage = 195;
		this -> itsjob = "Job";
	}
	Myjson(std::string name,int age,std::string job){
		this -> itsname = name;
		this -> itsage = age;
		this -> itsjob = job;
	}
	void print(void) const {
		std::cout<<"--------------------------------------------" <<std::endl;
		std::cout<<"name - "<< this -> itsname <<std::endl;
		std::cout<<"age - "<< this -> itsage <<std::endl;
		std::cout<<"job - "<< this -> itsjob <<std::endl;
	}
};

void delete_kavichka(std::string& object);
std::string jsonobject_classobject(Myjson obj, std::string objectarr);
int string_cast_int (std::string text);
std::string json_object(std::string json);
void delete_object(std::string& json);

std::string jsonobject_classobject(Myjson* obj, std::string objectarr){
	std::string tox[3] = {"","",""};
	int index = 0;
	for(int i = 0;i < 3;++i){
		for(int j = index;j < objectarr.length();++j){
			if(objectarr[j] != ','){
				tox[i] = tox[i] + objectarr[j];
			} else {
				index = j + 1; 
				break;
			}
		}
		std::string key = "";
        std::string value = "";
		int tox_index = 0;
        while(tox[i][tox_index] != ':'){
			key = key + tox[i][tox_index];
			++tox_index;
        }
		++tox_index;
		while(tox_index < tox[i].length() ){
			value = value + tox[i][tox_index];
			++tox_index;
		}
		if(key == "name"){
			obj -> set_name(value);	
		}else if(key == "age"){
			obj -> set_age( string_cast_int(value) );
		}else if(key == "job"){
			obj -> set_job(value);
		}
    }
}
void delete_kavichka(std::string& object){
	std::string newobject = "";
	for(int i = 0; i < object.length();++i){
		if(object[i] != '"' && object[i] != ' ' && object[i] != '\n'){
			newobject = newobject + object[i];
		}
	}
	object = newobject;
}
int string_cast_int (std::string text) {
    int tiv = text[0] - '0';
    for(int i = 1; i < text.length(); ++i ) {
        tiv	= (tiv * 10) + (text[i] - '0');
    }
    return tiv;
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
	
	Myjson jsonarray[3];
	
	std::string objectarr[3];
	for(int i = 0; i < 3;++i){
		objectarr[i] = json_object(json);
		delete_object(json);
	}
	for(int i = 0; i < 3;++i){
        delete_kavichka(objectarr[i]);
		jsonobject_classobject(&jsonarray[i],objectarr[i]);
    }
	for(int i = 0;i < 3; ++i){
		jsonarray[i].print();
	}
}
