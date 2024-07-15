#include <iostream>
#include <vector>
#include <string>
#include <queue>


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

    int minValue(TreeNode* root)
    {
        while(cur && cur->left)
        {
            cur = cur->left;
        }
        return cur->val;
    }
    bool findChain(TreeNode* root , int target , vector<TreeNode*> & ancestors)
    {
        ancestors.push_back(root);

        if(root->val == target)
        return true;
        if(target < root->val)
        findChain(root->left,target,ancestors);

        return root->right && findChain(root->right,target,ancestors);
    }
    
    TreeNode* getNext(vector<TreeNode*>& ancestors)
    {
        if(ancestors.size() == 0)
        return nullptr;
        TreeNode* node = ancestors.back();
        ancestors.pop_back();
        return node;
    }

    pair<bool,int> succesor(int target)
    {
        vector<TreeNode*> ancestors ;

        if(!findChain(root,target,ancestors))
        return make_pair(false,-1);

        TreeNode* child = getNext(ancestors);

        if(child->right)
        return make_pair(true,minValue(child->right));

        TreeNode* parent = getNext(ancestors);

        while(parent && parent->right == child)
        {
            child = parent ; 
            parent = getNext(ancestors);
        }
        if(parent)
        return make_pair(true,parent->val);

        return make_pair(false,-1);
    }
    TreeNode* deletNode(TreeNode* root , int target)
    {
        root = delete_node(root,target);
    }
    TreeNode* delete_node(TreeNode* root , int target)
    {
        if(!root)
        return nullptr;

        if(target < root->val)
        root->left = delete_node(root->left , target);
        else if(target > root->val)
        root->right = delete_node(root->right,target);
        else
        {
            TreeNode* tmp = root;
            if(!root->left && !root->right)
            root = nullptr;
            if(!root->right)
            root = root->left;
            if(!root->left)
            root = root->right;
            else
            {
                TreeNode* suc = minValue(root->right);
                root->val = suc->val;
                root->right = delete_node(root->right , root->val);
                tmp = nullptr;
            }
            if(tmp)
             delete tmp;
        }

        return root;
        

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
    // p1 : 
     bool isValidBst(TreeNode* root , long long mn = LLONG_MIN , long long mx = LLONG_MAX)
    {
        bool status = mn < root->val && root->val < mx ;
        if(!status)
        return false;

        bool isLeft = !root->left || isValidBst(root->left , mn , root->val);
        if(!isLeft)
        return false;

        bool isRight = !root->right || isValidBst(root->right , root->val , mx);
        return isRight;
         
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;
        return isValidBst(root);
       

       
        
    }
    // p2 : 
      void inorder(TreeNode* root, vector<int>& nodes)
    {
        if(!root)
        return ;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
        return 0 ;
        vector<int> nodes;
        inorder(root,nodes);
        k = k-1;
        return nodes[k];

        
    }
    //





















}













int main()
{


    return 0 ;
}