#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class AVL {
   private: 

    struct BinaryNode{
        int data {};
        int height{};
        BinaryNode* left{};
        BinaryNode* right{};


        BinaryNode(int data): data(data){

        }


        int ch_height(BinaryNode* node)
        {
            if(!node)
            return -1;

            return node->height;
        }

        void updated_height()
        { 
            height = 1 + max(ch_height(left),ch_height(right));
        }
        int balance_factor(){
            return ch_height(left)-ch_height(right);
        }

    };

    BinaryNode* root{};

    BinaryNode* right_rotation(BinaryNode* Q)
    {
        BinaryNode* p = Q->left;
        Q->left = p->right;
        p->right = Q;

        p->updated_height();
        Q->updated_height();

        return p;
    }

    BinaryNode* left_rotation(BinaryNode* P)
    {
        BinaryNode* Q = P->right;
        P->right = Q->left;
        Q->left = P;

        P->updated_height();
        Q->updated_height();

        return Q;
    }

    BinaryNode* balance (BinaryNode* node)
    {
        if(node->balance_factor()==2)
        {
            if(node->left->balance_factor()==-1)
            node->left = left_rotation(node->left)

            node = right_rotation(node);
        }

        else if(node->balance_factor()==-2)
        {
            if(node->right->balance_factor()==1)
            node->right = right_rotation(node->right);

            node = left_rotation(node);
        }

        return node;
    }

    void insert(int target , BinaryNode* root)
    {
        if(target < root->data)
        {
            if(!root->left)
            root->left = new BinaryNode();
            else
            root->left = insert(target,root->left)
        }
        else if(target > root->data)
        {
            if(!root->right)
            root->right = new BinaryNode();
            else
            root->right = insert(target , root->right);
        }

        root->updated_height();
        return balance(root);
    }


BinaryNode* min_node(BinaryNode* cur) {
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}


BinaryNode* delete_node(int target, BinaryNode* node) {
    if (!node) {
        return nullptr;
    }

    if (target < node->data) {
        node->left = delete_node(target, node->left);
    } else if (target > node->data) {
        node->right = delete_node(target, node->right);
    } else {
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->right) {
            BinaryNode* tmp = node->left;
            delete node;
            return tmp;
        } else if (!node->left) {
            BinaryNode* tmp = node->right;
            delete node;
            return tmp;
        } else {
           
            BinaryNode* mn = min_node(node->right);
            node->data = mn->data;  
            node->right = delete_node(mn->data, node->right);  
        }
    }

    
    if (node) {
        node->update_height();
        node = balance(node);
    }

    return node;
}


public: 

    void deleteValue(int target)
    {
        if(root)
        root = delete_node(target,root);
    }

    void insert(int target)
    {
        if(!root)
        root = new BinaryNode();
        else
        root = insert(target,root);
    }

    





    




















};




int main ()
{










    return 0 ; 
}