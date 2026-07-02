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
    bool isValidBST(TreeNode* root) {
        return inRange(root, -INT_MAX, INT_MAX);
    }
    bool inRange(TreeNode* root, int low, int high) {
        if(!root) return true;
        bool left = true;
        bool right = true;
        if(root->left) {
            left = root->left->val < root->val && high > root->left->val && low < root->left->val && inRange(root->left, low, root->val);
        }
        if(root->right) {
            right = root->right->val > root->val && low < root->right->val && high > root->right->val && inRange(root->right, root->val, high);
        }
        return left && right;
    }
};
