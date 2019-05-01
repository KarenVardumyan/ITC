#include<iostream>

#define sarqel_zangvac_5_chapani int arr[5] = {0,0,0,0,0};
#define mutqagrel_zangvaci_elementnery  for(int i = 0; i < 5; ++i){ std::cout<<"nermucel zangvaci "<<i+1<<"-rd andamy____"; std::cin>>arr[i];}
#define tpel_zangvaci_maximum_arjeqy int max = arr[0];for(int j = 1; j < 5;++j){if(max < arr[j]){max = arr[j];}else max = max;} std::cout<<"zangvaci mecaguyn arjeqn e -> "<<max<<std::endl;
int main() {

    sarqel_zangvac_5_chapani
    mutqagrel_zangvaci_elementnery
    tpel_zangvaci_maximum_arjeqy

    return 0;
}
