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
        int count {1}; // help me to count number of inversions
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

        int ch_count(BinaryNode* node)
        {
            if(!node)
            return 0;

            return node->count;
        }

        void updated_height()
        { 
            height = 1 + max(ch_height(left),ch_height(right));
        }
        void update_count()
        {
            count = 1 + ch_count(left) + ch_count(right);
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

        Q->updated_height();
        Q->update_count();
        p->updated_height();
        p->update_count();

        return p;
    }

    BinaryNode* left_rotation(BinaryNode* P)
    {
        BinaryNode* Q = P->right;
        P->right = Q->left;
        Q->left = P;

        P->updated_height();
        P->update_count();
        Q->updated_height();
        Q->update_count();

        return Q;
    }

    BinaryNode* balance (BinaryNode* node)
    {
        if(node->balance_factor()==2)
        {
            if(node->left->balance_factor()==-1)
            node->left = left_rotation(node->left);

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

    BinaryNode* insert(int target , BinaryNode* root)
    {
        if(target < root->data)
        {
            if(!root->left)
            root->left = new BinaryNode(target);
            else
            root->left = insert(target,root->left);
        }
        else if(target > root->data)
        {
            if(!root->right)
            root->right = new BinaryNode(target);
            else
            root->right = insert(target , root->right);
        }

        root->updated_height();
        root->update_count();
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
        node->updated_height();
        node->update_count();
        node = balance(node);
    }

    return node;
}


public: 

    BinaryNode* getRoot() const {
        return root;
    }


    void deleteValue(int target)
    {
        if(root)
        root = delete_node(target,root);
    }

    void insert(int target)
    {
        if(!root)
        root = new BinaryNode(target);
        else
        root = insert(target,root);
    }


    // hw1 p1 : 
    BinaryNode* lowerBound(int target,BinaryNode* root)
    {
        if(!root)
        return nullptr;

        if(target <= root->data) // it means may be I am the lower bound or one of my left childs
        {
            BinaryNode* ans = lowerBound(target,root->left);

            if(ans)
            return ans;

            return root;
        }
        return lowerBound(target,root->right);
    }
    
    // hw1 p2 : 
    BinaryNode* upperBound(int target, BinaryNode* root)
    {
        if(!root)
        return nullptr; 

        if(target < root->data)
        {
            BinaryNode* ans = upperBound(target, root->left);

            if(ans)
            return ans;

            return root;

        }
        return upperBound(target,root->right);
    }

    void printInorder(BinaryNode* root)
    {
        if(!root)
        return ;
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
    void printPreorder(BinaryNode* root)
    {
        if(!root)
        return ;
        cout<<root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    //hw1 p3: 

    int upperBoundCount(int target , BinaryNode* root)
    {
        if(!root)
        return 0 ;

        if(target < root->data)
        {
            int sum = 1;
            if(root->right)
            sum += root->right->count;

         return sum + upperBoundCount(target,root->left);
        }
        return upperBoundCount(target,root->right);
    }


    int countInversions(vector<int>&nums) // o(nlog(n))
    {
        int sum = 0 ;

        for(int i = 0 ; i<(int)nums.size() ; i++)
        {
            insert(nums[i]);
            sum += upperBoundCount(nums[i],root);

        }

        return sum;
    }

    // hw1 p4: 
    

    



    





    




















};




int main ()
{
    AVL tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(8);
    tree.insert(2);
    tree.insert(12);
    tree.insert(6);
    tree.printInorder(tree.getRoot());
    tree.printPreorder(tree.getRoot());










    return 0 ; 
}