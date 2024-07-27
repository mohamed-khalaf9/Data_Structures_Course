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
     TreeNode* minValue(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* delete_node(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }

        if (target < root->val) {
            root->left = delete_node(root->left, target);
        } else if (target > root->val) {
            root->right = delete_node(root->right, target);
        } else {
            
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                TreeNode* suc = minValue(root->right);
                root->val = suc->val;
                root->right = delete_node(root->right, suc->val);
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return delete_node(root, key);
    }
};