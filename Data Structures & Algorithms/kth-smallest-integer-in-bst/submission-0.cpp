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
    queue<int> q;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        for(int i = 0; i < k-1; i++) {
            q.pop();
        }
        return q.front();
    }
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        q.push(root->val);
        inorder(root->right);
    }
};
