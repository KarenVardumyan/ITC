#include <iostream>

#define sarqel_zangvac_5_chapani int max = -2147483648;
#define mutqagrel_zangvaci_elementnery std::cout << "Enter 5 value... \n";
#define tpel_zangvaci_maximum_arjeqy std::cout << funcMax(max) << std::endl;

int funcMax(int max);

int main() {

    sarqel_zangvac_5_chapani
    mutqagrel_zangvaci_elementnery
    tpel_zangvaci_maximum_arjeqy

    return 0;
}
int funcMax(int max){
    int array[5];
    for(int i = 0; i < 5; i++){
        std::cout << "Enter [" << i << "] = ";
        std::cin >> array[i];
    }
    for(int i = 0; i < 5; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}
