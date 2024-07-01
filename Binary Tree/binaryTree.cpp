#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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

    void Level_order_traversal(TreeNode* root)
    {
        queue<TreeNode*> nodes ; 
        nodes.push(root);
        int level = 0 ;
        while(!nodes.empty())
        {
        cout<<"level : "<<level<<endl;
        int sz = nodes.size();
        while(sz--)
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            cout<<cur->data<<" ";
            if(cur->left)
            nodes.push(cur->left);
            if(cur->right)
            nodes.push(cur->right);
        }
        cout<<endl;
        ++level;
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
    // p4 : 
    bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
    }   
    int sumOfLeftLeaves(struct TreeNode *root) {
		if (!root)
			return 0;

		int sum = 0;
		if (isLeaf(root->left))
			sum += root->left->data;

		sum += sumOfLeftLeaves(root->left);
		sum += sumOfLeftLeaves(root->right);

		return sum;
	}   
    // p5 : 
    int heightOfTree(TreeNode* root)
    {
        if(!root)
        return 0 ;

        int L = heightOfTree(root->left);
        int R = heightOfTree(root->right);

        return max(L,R)+1;

    }
    bool isPerfect(TreeNode* root , int h )
    {
        if(isLeaf(root))
        return h == 0;

        if(!root->left && root->right || !root->right && root->left )
        return false ;

        return isPerfect(root->left , h-1 ) && isPerfect(root->right , h-1);

    }
    bool isPerfect(TreeNode* root )
    {
        return isPerfect(root , heightOfTree(root));

    }

    //::::::::::::::::::::::::::::::::::: homework 2 :::::::::::::::::::::::::::::::::::::::::::::

    // p3 :
    int maxSoFar = 0 ; 
    int heightOfTree(TreeNode* root)
    {
        if(!root)
        return 0 ;

        int Lh = heightOfTree(root->left);
        int Rh = heightOfTree(root->right);

        maxSoFar = max(maxSoFar,Lh+Rh);

        return 1+max(Lh,Rh);


    }
    int diemeterOfTree(TreeNode* root)
    {
        if(!root)
        return 0 ;

        heightOfTree(root);
        return maxSoFar;
    }
    // p1 : 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) return results; 
        
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        bool forwardLevel = true;
        
        while (!nodes.empty()) {
            int sz = nodes.size();
            vector<int> result;
            while (sz--) {
                TreeNode* cur = nullptr;
                if (forwardLevel) {
                    cur = nodes.front();
                    nodes.pop_front();

                    if (cur->left)
                        nodes.push_back(cur->left);
                    if (cur->right)
                        nodes.push_back(cur->right);
                } else {
                    cur = nodes.back();
                    nodes.pop_back();

                    if (cur->right)
                        nodes.push_front(cur->right);
                    if (cur->left)
                        nodes.push_front(cur->left);
                }
                result.push_back(cur->data);
            }
            forwardLevel = !forwardLevel;
            results.push_back(result);
        }

        return results;
    }
    // p2 : 
    
    

    










};




int main()
{
    BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
    tree.add( {3,5,22} , {'R', 'R','L'});
    
    tree.Level_order_traversal(tree.root);

	
    
  
	

    
   

    
    



    return 0 ;
}