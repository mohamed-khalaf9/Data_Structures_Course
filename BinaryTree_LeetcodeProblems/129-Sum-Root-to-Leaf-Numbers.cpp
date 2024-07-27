/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
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
};