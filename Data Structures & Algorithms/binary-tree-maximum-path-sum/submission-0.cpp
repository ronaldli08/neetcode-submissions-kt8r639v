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
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
         pathSum(root);
         return maxVal;
    }
    int pathSum(TreeNode* root) {
        if(!root) return 0;
        int l = max(0,pathSum(root->left));
        int r = max(0, pathSum(root->right));
        int path = root->val + l + r;
        
        maxVal = max(maxVal, path); 
        return root->val + max(l, r);
    }
};
