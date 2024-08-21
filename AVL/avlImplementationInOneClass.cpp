#include <iostream>

using namespace std;


class AVL{
    private:

    int data {};
    int height {};
    AVL* left {};
    AVL* right {};

    public:

    AVL(int data):data(data){

    }



    void insertHelper(int value)
    {
        


    }

    void insert(int value)
    {
        this = insertHelper(value);

    }

}







int main()
{



    return 0;
}