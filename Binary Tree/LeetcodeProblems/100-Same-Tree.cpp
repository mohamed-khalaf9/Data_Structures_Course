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
};