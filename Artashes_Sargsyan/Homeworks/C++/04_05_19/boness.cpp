#include <iostream>
#include <ctime>
#include <iomanip>

void print(char** arr,int x,int y){
    for(int i = 0; i < 3; ++i){
        for(int j = x; j < y; ++j){
            std::cout << arr[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void printAll(char** arr1,char** arr2){
    for (int i = 0; i < 3; i++) {
        std::cout << std::string(10, ' ');
        for (int j = 0; j < 13; j++)
            std::cout << std::setw(2) << arr1[i][j];
        std::cout << std::string(20, ' ');
        if (i < 3)
            for (int j = 0; j < 13; j++)
                std::cout << std::setw(2) << arr2[i][j];
        std::cout << std::endl;
    }
}

void bones(char** arr,int p1,int p2,int p3){
    char a = '*';
    for(int i = 0,j = 0; i < 3; ++i){
        arr[i][j] = '|';
    }
    for(int i = 0,j = 4; i < 3; ++i){
        arr[i][j] = '|';
    }
    for(int i = 0,j = 8; i < 3; ++i){
        arr[i][j] = '|';
    }
    for(int i = 0,j = 12; i < 3; ++i){
        arr[i][j] = '|';
    }                       
    switch(p1){
        case 1:
            arr[1][2] = a;
            break;
        case 2:
            arr[0][1] = a;
            arr[2][3] = a;
            break;
        case 3:
            arr[0][1] = a;
            arr[1][2] = a;
            arr[2][3] = a;
            break;
        case 4:
            arr[0][1] = a;
	    arr[0][3] = a;
            arr[2][1] = a;
            arr[2][3] = a;
            break;
        case 5:
            arr[0][1] = a;
            arr[0][3] = a; 
            arr[2][1] = a;
            arr[2][3] = a;
            arr[1][2] = a;
            break;
        case 6:
            arr[0][1] = a;
            arr[0][3] = a;
            arr[1][1] = a;
            arr[1][3] = a;
            arr[2][1] = a;
            arr[2][3] = a;
            break;
    }
        switch(p2){
        case 1:
            arr[1][6] = a;
            break;
        case 2:
            arr[0][5] = a;
            arr[2][7] = a;
            break;
        case 3:
            arr[0][5] = a;
            arr[1][6] = a;
            arr[2][7] = a;
            break;
        case 4:
            arr[0][5] = a;
            arr[2][5] = a;
            arr[0][7] = a;
            arr[2][7] = a;
            break;
        case 5:
            arr[0][5] = a;
            arr[2][5] = a;
            arr[0][7] = a;
            arr[2][7] = a;
            arr[1][6] = a;
            break;
        case 6:
            arr[0][5] = a;
            arr[2][5] = a;
            arr[0][7] = a;
            arr[2][7] = a;
            arr[1][5] = a;
            arr[1][7] = a;
            break;
    }
        switch(p3){
        case 1:
            arr[1][10] = a;
            break;
        case 2:
            arr[0][9] = a;
            arr[2][11] = a;
            break;
        case 3:
            arr[0][9] = a;
            arr[2][11] = a;
            arr[1][10] = a;
            break;
        case 4:
            arr[0][9] = a;
            arr[2][9] = a;
            arr[0][11] = a;
            arr[2][11] = a;
            break;
        case 5:
            arr[0][9] = a;
            arr[2][9] = a;
            arr[0][11] = a;
            arr[2][11] = a;
            arr[1][10] = a;
            break;
        case 6:
            arr[0][9] = a;
            arr[2][9] = a;
            arr[0][11] = a;
            arr[2][11] = a;
            arr[1][9] = a;
            arr[1][11] = a;
            break;
    }
}

int main(){
    char space = ' ';
    int sumcomp = 0,sumplayer = 0;
    
    srand(time(NULL));
    int player1 = rand() % 6 + 1;
    int player2 = rand() % 6 + 1;
    int player3 = rand() % 6 + 1;
    int comp1 = rand() % 6 + 1;
    int comp2 = rand() % 6 + 1;
    int comp3 = rand() % 6 + 1;
    
    sumplayer = player1 + player2 + player3;
    sumcomp = comp1 + comp2 + comp3;
    
    char** arr1 = new char*[3];
    for(int i = 0; i < 3; ++i){
        arr1[i] = new char[13];
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 13; ++j){
            arr1[i][j] = space;
        }
    }
    
    char** arr2 = new char*[3];
    for(int i = 0; i < 3; ++i){
        arr2[i] = new char[13];
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 13; ++j){
            arr2[i][j] = space;
        }
    }

    bones(arr1,player1,player2,player3);
    bones(arr2,comp1,comp2,comp3);
    std::cout << "Xax@ skselu hamar sexmeq ENTER...\n";
    std::cin.ignore();
    std::cout << "Player \n";
    print(arr1,0,5);
    std::cout << "Comp \n";
    print(arr2,0,5);  
    std::cout << "Sexmeq ENTER sharunakelu hamar...";
    std::cin.ignore();
    std::cout << "Player \n";
    print(arr1,4,9);
    std::cout << "Comp \n";
    print(arr2,4,9);
    std::cout << "Sexmeq ENTER sharunakelu hamar...";
    std::cin.ignore();
    std::cout << "Player \n";
    print(arr1,8,13);
    std::cout << "Comp \n";
    print(arr2,8,13);  
    std::cout << "Sexmeq ENTER sharunakelu hamar...";
    std::cin.ignore();
    std::cout << "                                    Ardyunqneri ampopum !!!\n\n\n";
    std::cout << "            Dzer havaqac miavorner@: " << sumplayer;
    std::cout << "                  Compi havaqac miavorner@: " << sumcomp << "\n\n";
    printAll(arr1,arr2);
    std::cout << "\n\n";

    if(sumplayer > sumcomp){
        std::cout << "                                    Duq haxteciq URAaaaaa!\n";
    } else if (sumplayer < sumcomp){
        std::cout << "                             Haxtec Hamakargich@...(((...chURAaaaa!\n";
    } else {
        std::cout << "                                           Voch voqi...\n";
    }
    
    
    for(int i = 0; i < 3; ++i) {
        delete [] arr1[i];
    }
        delete [] arr1;
    
    for(int i = 0; i < 3; ++i) {
        delete [] arr2[i];
    }
        delete [] arr2;
    
    return 0;
}
