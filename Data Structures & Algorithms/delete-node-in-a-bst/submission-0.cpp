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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key) {
            if(root->left == nullptr) {
                if(root->right == nullptr) {
                    return nullptr;
                }
                else {
                    return root->right;
                }
            }
            else {
                if(root->right == nullptr) {
                    return root->left;
                }
                else {
                    TreeNode* next = root->right;
                    while(next->left != nullptr) {
                        next = next->left;
                    }
                    int v = next->val;
                    TreeNode* ans = deleteNode(root, next->val);
                    ans->val = v;
                    return ans;
                }
            }
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};