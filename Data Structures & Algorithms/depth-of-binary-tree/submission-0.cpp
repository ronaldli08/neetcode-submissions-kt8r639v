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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int maxD = 1;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            maxD = max(maxD, front.second);
            if(front.first->left) q.push({front.first->left, front.second + 1});
            if(front.first->right) q.push({front.first->right, front.second + 1});
        }
        return maxD;
    }
};
