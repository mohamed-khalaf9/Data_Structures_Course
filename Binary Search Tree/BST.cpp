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
    // problem on leetcode : 
     int curSum = 0;
    bool isLeaf(TreeNode* root)
    {
        return root && !root->left && !root->right;
    }
    void sumNumbersHelper(TreeNode* root , int pathSum =0)
    {
        pathSum = pathSum * 10 + root->val;
        if(isLeaf(root))
        curSum += pathSum;

        if(root->left)
        sumNumbersHelper(root->left,pathSum);
        if(root->right)
        sumNumbersHelper(root->right,pathSum);

    }
    int sumNumbers(TreeNode* root) {
        if(!root)
        return 0;
        sumNumbersHelper(root,0);
        return curSum;
        
        
        
    }
    // easy problem on leetcode : 
    string canonical(TreeNode* root) {
    if (!root) {
        return "()";
    }

    string rep = "(" + to_string(root->val);

    if (root->left) {
        rep += canonical(root->left);
    } else {
        rep += "()";
    }

    if (root->right) {
        rep += canonical(root->right);
    } else {
        rep += "()";
    }

    rep += ")";

    return rep;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        string repP = canonical(p);
        string repQ = canonical(q);

        return repP == repQ;
        
    }
    // one easy problem on leet code 
     TreeNode* invertTree(TreeNode* root) {
        if(!root)
        return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp ;

        invertTree(root->left);
        invertTree(root->right);

        return root;
        
    }
    // solved problem on leetcode 
     vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> nodes ;
        nodes.push(root);

        while(!nodes.empty())
        {
            int sz = nodes.size();
            vector<int> levelN;
            while(sz--)
            {
                TreeNode* cur = nodes.front();
                nodes.pop();

                if(cur->left)
                nodes.push(cur->left);
                if(cur->right)
                nodes.push(cur->right);

                levelN.push_back(cur->val);

            }
            res.push_back(levelN);
           
        }

        return res;
        
    }
    // just med problem on leetcode : 
     vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        deque<TreeNode*> nodes ;
        nodes.push_back(root);
        res.push_back(root->val);
        
        while(!nodes.empty())
        {
            int sz = nodes.size();
            while(sz--)
            {
            TreeNode* cur = nodes.front();
            nodes.pop_front();

            if(cur->left)
            nodes.push_back(cur->left);
            if(cur->right)
            nodes.push_back(cur->right);
            }
            if(nodes.empty())
            break;
            TreeNode* toBePushed = nodes.back();

            res.push_back(toBePushed->val);
        }

        return res;
    } 
    // just easy problem on friday on leetcode 
     vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res ;
        if(!root) return res;
        queue<TreeNode*> nodes ;
        nodes.push(root);
        double curCount = 0;
        while(!nodes.empty())
        {
            int sz = nodes.size();
            curCount = sz;
            double sum = 0 ;
            while(sz--)
            {
                TreeNode* cur = nodes.front();
                nodes.pop();

                if(cur->left)
                nodes.push(cur->left);
                if(cur->right)
                nodes.push(cur->right);

                sum += cur->val;
            }
            res.push_back(sum/curCount);
        }
        return res;
    }
    // 
    
    

    






};












int main()
{
    return 0 ;
}