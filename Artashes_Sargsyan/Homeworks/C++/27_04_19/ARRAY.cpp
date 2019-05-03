#include <iostream>

int menu();

int Maximum(int array[],int MinOrMax,int SIZE);

void bubbleSort(int array[],int UpOrDown,int SIZE);

int arithmeticMean(int array[],int SIZE);

void LogicMenu(int array[],int SIZE);

int main ()
{       int SIZE = 5;
        int* array = new int[SIZE];
        LogicMenu(array,SIZE);
	delete [] array;
        
return 0;
}

int menu()
{
        int submenu;
        std::cout << "************************MENU**********************\n\n";
        std::cout << "         Check (1)..Enter the Values of Array.\n";
        std::cout << "         Check (2)..For replace SIZE of Array.\n";
        std::cout << "         Check (3)..Max value.\n";
        std::cout << "         Check (4)..Min value.\n";
        std::cout << "         Check (5)..Sort to up.\n";
        std::cout << "         Check (6)..Sort to down.\n";
        std::cout << "         Check (7)..Arithmetic Mean.\n";
        std::cout << "         Check (8)..Quit...\n\n";
        std::cout << "         Default size of array is 5\n\n";
        std::cin >> submenu;
    return submenu;
}

int Maximum(int array[],int MinOrMax,int SIZE)
{
    int Max = array[0];
    int Min = array[0];
    if(MinOrMax == 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (Max < array[i])
            {
                Max = array[i];
            }
        }
            return Max;
    }else {
                for(int i = 0; i < SIZE; i++)
                {
                    if (Min > array[i])
                    {
                        Min = array[i];
                    }
                }
                return Min;
            }
}

void bubbleSort(int array[],int UpOrDown,int SIZE)
{
    int tmp;
    if(UpOrDown == 0)
    {
        for(int i = 0; i < SIZE - 1; ++i)
        {            
            for(int j = 0; j < SIZE - 1; ++j)
            {     
                if (array[j + 1] < array[j]) 
                {
                    tmp = array[j + 1]; 
                    array[j + 1] = array[j]; 
                    array[j] = tmp;
                }
            }
        }
    }   
    else   
    {
        for(int i = 0; i < SIZE - 1; ++i)
        {            
            for(int j = 0; j < SIZE - 1; ++j)
            {     
                if (array[j + 1] > array[j]) 
                {
                    tmp = array[j + 1]; 
                    array[j + 1] = array[j]; 
                    array[j] = tmp;
                }
            }
        } 
    }
}

int arithmeticMean(int array[],int SIZE)
{
    int Mean = 0,Sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
       Sum += array[i]; 
    }
    Mean = Sum / 5;
    return Mean;
}

void LogicMenu(int array[], int SIZE)
{
    bool exit = false;
    for( ; ; )
    {
        int submenu = menu();
        switch(submenu)
        {
            case(1):
                    std::cout << "Enter elements of Array...\n";
                    for (int i = 0; i < SIZE; i++)
                    {
                        std::cin >> array[i];
                    };
                break;
            case(2):
                std::cout << "New Size is equal =  " << std::endl;
                std::cin >> SIZE;
                break;
            case(3):
                std::cout << "Max value is " << Maximum(array,0,SIZE) << std::endl;
                break;
            case(4):
                std::cout << "Min value is " << Maximum(array,1,SIZE) << std::endl;
                break;
            case(5):
                bubbleSort(array,0,SIZE);
                    for(int i = 0; i < SIZE; i++)
                    {
                        std::cout << "          array[" << i << "] = " << array[i] << std::endl;
                    }
                break;
            case(6):
                bubbleSort(array,1,SIZE);
                    for(int i = 0; i < SIZE; i++)
                    {
                        std::cout << "          array[" << i << "] = " << array[i] << std::endl;
                    }
                break;
            case(7):
                    std::cout << "Arithmetic Mean is equal " << arithmeticMean(array,SIZE) << std::endl;
                break;    
            case(8):
                exit = true;
                break;
                default:
                std::cout << "please select valid number of submenu..\n";
                break;
        }
        if (exit)
        {
            break;
        }
    }
}