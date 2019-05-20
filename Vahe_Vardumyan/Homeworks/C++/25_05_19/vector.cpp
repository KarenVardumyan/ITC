#include <iostream>

class vector
{
    int* vec;
    int size;
    
public:
    vector()
    {
        size = 10;
        for(int i = 0; i < size; i++)
        {
            vec = new int[10];
        }
        for(int i = 0; i < size; i++)
        {
            vec[i] = i;
        }
    }
    
    ~vector()
    {
    }
    
    void push_back(int a)
    {
        int* new_vec;
        new_vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            new_vec[i] = vec[i];
        }
        size++;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i];
        }
        delete new_vec;
        vec[size - 1] = a;
    }
    
    void psuh_front(int a)
    {
        int* new_vec;
        new_vec = new int[size + 1];
        new_vec[0] = a;
        for(int i = 0; i < size; i++)
        {
            new_vec[i + 1] = vec[i];
        }
        size++;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i];
        }
        delete new_vec;
    }
    
    void insert_at_index(int index, int a)
    {
        size++;
        int* new_vec;
        new_vec = new int[size];
        for(int i = 0; i < index - 1; i++)
        {
            new_vec[i] = vec[i];
        }
        new_vec[index - 1] = a;
        for(int i = index; i < size; i++)
        {
            new_vec[i] = vec[i - 1];
        }
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i];
        }
        delete new_vec;
    }
   
    void pop_back()
    {
        int* new_vec;
        new_vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            new_vec[i] = vec[i];
        }
        size--;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i];
        }
        delete new_vec;
    }

    void front_back()
    {
        int* new_vec;
        new_vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            new_vec[i] = vec[i];
        }
        size--;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i + 1];
        }
        delete new_vec;
    }
    
    void pop_at_index(int index)
    {
        int* new_vec;
        new_vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            new_vec[i] = vec[i];
        }
        size--;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < index - 1; i++)
        {
            vec[i] = new_vec[i];
        }
        vec[index - 1] = new_vec[index];
        for(int i = index; i < size; i++)
        {
            vec[i] = new_vec[i + 1];
        }
        delete new_vec;
    }
    
    void resize(int new_size)
    {
        int* new_vec;
        new_vec = new int[new_size];
        if(new_size <= size)
        {
            for(int i = 0; i < new_size; i++)
            {
                new_vec[i] = vec[i];
            }
        }
        else
        {
            for(int i = 0; i < size; i++)
            {
                new_vec[i] = vec[i];
            }
            for(int i = size; i < new_size; i++)
            {
                new_vec[i] = 0;
            }
        }
        size = new_size;
        delete vec;
        vec = new int[size];
        for(int i = 0; i < size; i++)
        {
            vec[i] = new_vec[i];
        }
        delete new_vec;
    }
    
    void print()
    {
        for(int i = 0; i < size; i++)
        {
            std::cout<< vec[i] << ' ';
        }
        std::cout<<std::endl;
    }
};

int main()
{
    vector BEEM;
    BEEM.print();
    BEEM.push_back(100);
    BEEM.print();
    BEEM.psuh_front(50);
    BEEM.print();
    BEEM.insert_at_index(4, 4);
    BEEM.print();
    BEEM.pop_back();
    BEEM.print();
    BEEM.front_back();
    BEEM.print();
    BEEM.pop_at_index(3);
    BEEM.print();
    BEEM.resize(4);
    BEEM.print();
    BEEM.resize(10);
    BEEM.print();
    return 0;
}