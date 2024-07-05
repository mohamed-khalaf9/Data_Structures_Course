#include <iostream>
#include <vector>


using namespace std;

class TreeNode{
    public:
    int val{};
    TreeNode* left{};
    TreeNode* right{};

    TreeNode(int val_): val(val_){

    }

};

class BinarySearchTree{
    public:
    TreeNode* root{};

    BinarySearchTree(int val):root(new TreeNode(val)){

    }



    bool search(TreeNode* root , int target)
    {
        if(!root)
        return false;

        if(root->val == target)
        return true;

        if(target<root->val)
        return search(root->left,target);

        return search(root->right,target);
    }

    void insert(TreeNode* root , int target)
    {
        if(target<root->val)
        {
            if(!root->left)
            root->left = new TreeNode(target);
            else
            insert(root->left,target);
        }
        else if(target>root->val)
        {
            if(!root->right)
            root->right = new TreeNode(target);
            else
            insert(root->right,target);
        }
        
    }

    void insert(int target)
    {
        insert(root , target );
    }

};

class Solutions{
//:::::::::::::::::::::::::::::::::::::::: homework1 ::::::::::::::::::::::::::::::::::::::
// p1 : 
 TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
        return nullptr;
        if(val == root->val)
        return root;
        if(val<root->val)
        return searchBST(root->left,val);

        return searchBST(root->right,val);
        
    }

// p2 : 
 TreeNode* _sortedArrayToBST(vector<int>& nums , int start , int end)
    {
        if(start>end)
        return nullptr;

        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums,start,mid-1);
        root->right = _sortedArrayToBST(nums , mid+1 , end);

        return root;


    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums,0,(int)nums.size()-1);
       
    }
    
    //::::::::::::::::::::::::::::::::::::::::::::::::: homework 2 ::::::::::::::::::::::::::::::::::::::::

    // p3 : 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
         return lowestCommonAncestor(root->left,p,q);

        if(p->val > root->val && q->val > root->val)
         return lowestCommonAncestor(root->right,p,q);


        return root;

        
        
    }
    
    
    // friday problem : 
     int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root)
    {
        if(!root)
        return ;
        
        
        inorder(root->left);

        if(prev!=nullptr)
        minDiff=min(minDiff,abs(root->val - prev->val));

        prev=root;

        
        inorder(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        if(!root)
        return 0;
        inorder(root);
        return minDiff;
       
    }






};












int main()
{
    return 0 ;
}