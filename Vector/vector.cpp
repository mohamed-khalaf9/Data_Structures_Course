#include <iostream>
#include <assert.h>

using namespace std;


class Vector{

    private:

    int* arr = nullptr;
    int size = 0 ;
    int capacity{} ;
    int total_elements = 0 ;


    void resize_vector()
    {
        capacity = 2 * capacity;
        int* arr2 = new int[capacity]{};

        for(int i = 0 ; i < size ; i++)
        {
            arr2[i] = arr[i];
        }

        swap(arr,arr2);

        delete[] arr2;

    }


    public: 

    Vector(int size_):size(size_){
        if(size<0)
        size = 1 ;

        capacity = 2 * size;

        arr = new int[capacity]{};
     }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;

    }
    int get(int idx)
    {
        assert(0<=idx && idx<size);
        return arr[idx];
        
    }

    void set(int idx , int val)
    {
        assert(0<=idx && idx < size);
        arr[idx] = val;

    }

    void print()
    {
        for(int i = 0 ; i<total_elements ; i++)
        cout<<arr[i];
    }

    int find(int val)
    {
        for(int i = 0 ; i<size ; i++)
        {
            if(arr[i]==val)
            return i ;
        }

        return -1 ;
    }

    int get_front()
    {
        return arr[0];
    }
    
    int get_back()
    {
        return arr[size-1];
    }

    void push_back(int val)
    {
        if(size == capacity)
        resize_vector();

        arr[total_elements++] = val;


    }

    void insert(int idx , int val)
    {
        if(size == capacity)
        resize_vector();

        for(int i = size ; i > idx ; i--)
        arr[i] = arr[i-1];

        arr[idx] = val ;
        ++total_elements;
    }

    //::::::::::::::::::::::::::::::::::: homework ::::::::::::::::::::::::::::::::::

    // p 1 : 

    void right_rotate()
    {
        int tmp = arr[total_elements-1];

        for(int i = total_elements-1 ; i >= 0; i--)
        arr[i] = arr[i-1];
        
        arr[0] = tmp ; 
    }

    // p2 : 
    void left_rotate()
    {
        int tmp = arr[0];

        for(int i = 0 ; i <total_elements ; i++)
        {
            arr[i] = arr[i+1];
        }

        arr[total_elements-1] =  tmp;
    }

    // p3 : 

    void right_rotate_with_steps(int steps)
    {
        int rounds = steps % total_elements;
        while(rounds--)
        {
            right_rotate();
        }

    }

    // p4 : 
    
    void delete_position(int idx)
    {
        for(int i = idx ; i < total_elements -1 ; i ++)
        {
            arr[i] = arr[i+1];
        }
        --total_elements;
    }

    // p5 : 
    int find_transpostion(int val)
    {
        for(int i = 0 ; i < total_elements ; i++)
        {
            if(arr[i] == val)
            {
                if(i==0)
                return i;

                swap(arr[i],arr[i-1]);

                return i - 1;
            }
        }

        return -1 ;
    }




};

int main()
{
    Vector v(6);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    v.print();
    cout<<endl;
    cout<<v.find_transpostion(0)<<endl;
    v.print();
    cout<<endl;
    cout<<v.find_transpostion(3);
    cout<<endl;
    v.print();
    cout<<endl;
    cout<<v.find_transpostion(-1);






    return 0 ;
}