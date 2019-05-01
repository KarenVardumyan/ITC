#include<iostream>

void calculator(int tiv1,int tiv2,char nshan);
void calculator(char simvol1,char simvol2,char nshan);

int main() {

    calculator('1', '2' , '+');
    calculator( 2, 1 , '+');

    return 0;
}

void calculator(int tiv1,int tiv2,char nshan){
	if(nshan == '+'){				   
		std::cout<<"2 + 1 = " <<tiv1 + tiv2<<std::endl; 
	}
}
void calculator(char simvol1,char simvol2,char nshan){
	int tiv1 = simvol1 - '0';
	int tiv2 = simvol2 - '0';
	if(nshan == '+'){
		std::cout<<"'1' + '2' ="<<tiv1 + tiv2<<std::endl;	
	}
}

