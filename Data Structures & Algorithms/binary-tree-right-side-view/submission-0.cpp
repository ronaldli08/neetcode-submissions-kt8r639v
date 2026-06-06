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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0;
        while(!q.empty()) {
            pair<TreeNode*,int> front = q.front();
            q.pop();
            if(level == front.second) {
                ans.push_back(front.first->val);
                ++level;
            }
            if(front.first->right != nullptr) q.push({front.first->right, front.second + 1});
            if(front.first->left != nullptr) q.push({front.first->left, front.second + 1});
        }
        return ans;
    }
};
