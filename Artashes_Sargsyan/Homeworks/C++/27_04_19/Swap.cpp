#include <iostream>

int Swap(int& One,int& Two);

int main(){
    int One = 0,Two = 0;
    std::cout << "Enter value One.. ";
    std::cin >> One;
    std::cout << "Enter value Two.. ";
    std::cin >> Two;
    Swap(One,Two);
    std::cout << "Value One.. " << One << std::endl;
    std::cout << "value Two.. " << Two << std::endl;
    return 0;
}

int Swap(int& One,int& Two){
    int tmp = One;
    One = Two;
    Two = tmp;
    return 0;
}
