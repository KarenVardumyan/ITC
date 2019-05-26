#include <iostream>
#include <string>
#include <fstream>

void NewJsonFileCreate(void);

int main()
{
    NewJsonFileCreate();
    return 0;
}

void NewJsonFileCreate(void){
    std::string str = "[\n", name = "", age = "", job = "", null = "",YesOrNo = "";

    for(int i = 0; ; ++i){
        std::cout << "name of Person # " << i << "\n";
        std::cin >> name;
        str += "\t{\n\t\t\"name\":\"" + name + "\",\n";
        std::cout << "age of person # " << i << "\n";
        std::cin >> age;
        str += "\t\t\"age\":\"" + age + "\",\n";
        std::cout << "job of person # " << i << "\n";
        std::cin >> job;
        str += "\t\t\"job\":\"" + job + "\"\n\t},\n";
        name = null;
        age = null;
        job = null;
        std::cout << "For EXIT please enter 0 for continue please enter any key...\n" << "EXIT..0..continue..??\n";
        std::cin >> YesOrNo;
        if(YesOrNo[0] == '0'){
            break;
        }
        YesOrNo = null;
    }
    int size = str.length();
    str[size - 2] = '\n';
    str[size - 1] = ']';
    str += '\n';
    std::cout << str;
    std::ofstream out("output.json");
    out << str;
    out.close();
}
