#include <iostream>

const int n=500;

int main(){
    int a = 0;
    char stroka[n];
    std::cin.getline(stroka,n);
    std::cout << stroka << std::endl; 
    for(int i = 0; stroka[i] != '\0'; ++i){
        a = stroka[i] - '0';
	if((a >= 49 && a <= 74) || (a >= 17 && a <= 42)){
	   std::cout << stroka[i];
        }
    }
    return 0;
}
