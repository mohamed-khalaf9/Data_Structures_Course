#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;



class BinaryHeap{
    private:
    
    int *arr{};
    int size{};
    int capacity{1000};

    int left(int indix)
    {
        int L = 2*indix+1;
        if(L>=size)
        return -1;

        return L;    
    }

    int right(int indix)
    {
        int R = 2*indix+2
        if(R>=size)
        return -1 ;

        return R;
    }
    
    int parent(int indix)
    {
       if(indix == 0)
       return -1;
       else
       return (indix-1)/2;
    }

    void heapifyUp(int childPos)
    {
        int parPos = parent(childPos);
        if(childPos==0 || arr[parPos]<arr[childPos])
        return;

        swap(arr[parPos],arr[childPos]);
        heapifyUp(parPos);
    }
    void heapifyDown(int parPos)
    {
        int childPos = left(parPos);
        int rightChild = right(parPos);
        if(childPos == -1)
        return ;
        if(rightChild != -1 && arr[rightChild] < arr[childPos])
        childPos = rightChild;

        if(arr[parpos]>arr[childPos])
        {
            swap(arr[parPos],arr[childPos]);
            heapifyDown(childPos);
        }
    }


    public:

    BinaryHeap()
    {
        arr = new int[capacity]{};
        size = 0 ;
    }

    void push(int key)
    {
        assert(size+1<=capacity);
        arr[size++]=key;
        heapifyUp(size-1);
    }
    bools isEmpty()
    {
        return size == 0 ;
    }
    int top()
    {
        assert(!isEmpty());
        return arr[0];
    }
    void pop()
    {
        assert(!isEmpty());
        arr[0] = arr[--size];
        heapifyDown(0);
    }

    













};















int main()
{



    return 0 ;
}
