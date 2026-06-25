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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int good = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            good += front.first->val >= front.second ? 1 : 0;
            if(front.first->left) 
                q.push({front.first->left, max(front.second, front.first->val)});
            if(front.first->right) 
                q.push({front.first->right, max(front.second, front.first->val)});
        }
        return good;
    }
};
