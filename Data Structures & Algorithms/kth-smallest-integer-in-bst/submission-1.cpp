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
    int counter;
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        counter = k;
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        if(--counter == 0) ans = root->val;
        inorder(root->right);
    }
};
