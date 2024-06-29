#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

class TreeNode{
    public:
    int data {};
    TreeNode* left{};
    TreeNode* right{};

    TreeNode(int data_):data(data_){

    }
};

class BinaryTree{
    public:

    TreeNode* root{};

    BinaryTree(int data): root(new TreeNode(data)){

    }

    void _printInorder(TreeNode * cur){
        if(!cur)
        return;

        _printInorder(cur->left);
        cout<<cur->data<<" ";
        _printInorder(cur->right);
    }

    void printInorder()
    {
        _printInorder(this->root);
    }

    void add(vector<int>values , vector<char> directions)
    {
        assert(values.size() == directions.size());
        TreeNode* cur = this->root;
        for(int i = 0 ; i < (int)directions.size() ; i++)
    {
        if(directions[i]=='L')
        {
            if(!cur->left)
            cur->left = new TreeNode(values[i]);
            else
            assert(values[i] == cur->left->data);
            
            cur = cur->left;
        }
        else {
            if(!cur->right)
            cur->right = new TreeNode(values[i]);
            else
            assert(values[i] == cur->right->data);

            cur = cur->right;
        }

    }
        

    }






};

class Solutions{
    public:
    //:::::::::::::::::::::::::::::::::: homework 1 :::::::::::::::::::::::::::::::::::::
    // p1 :
    int treeMax(TreeNode* root)
    {
        if(!root)
        return 0;

        int res = root->data;
        if(root->left)
        res = max(res,treeMax(root->left));
        if(root->right)
        res = max(res,treeMax(root->right));

        return res;
    }
    // p2 : 
      int maxDepth(TreeNode* root) {
        if(!root)
        return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1+max(left,right);
    }
    // p3 : 
    bool _hasPathSum(TreeNode* root , int targetSum , int sum=0)
    {
        if(!root)
        return false;

        
        sum += root->data;
        
        if(!root->left && !root->right)
         {
            return targetSum == sum ;
         }
         return _hasPathSum(root->left , targetSum , sum)||
        _hasPathSum(root->right , targetSum , sum);

        
         
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return _hasPathSum(root , targetSum , 0);
    }









};




int main()
{
    BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	tree.printInorder();
    cout<<endl;
	// 7 4 8 2 5 9 1 3 10 6

    cout<<Solutions().treeMax(tree.root);
   

    
    



    return 0 ;
}