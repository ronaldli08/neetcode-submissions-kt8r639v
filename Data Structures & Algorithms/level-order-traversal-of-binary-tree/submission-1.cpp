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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        ans.push_back({root->val});
        queue<pair<TreeNode*, int>> q;
        vector<int> level;
        if(root->left != nullptr) {
            q.push({root->left, 1});
        }
        if(root->right != nullptr) {
            q.push({root->right, 1});
        }
        int i = 1;
        while(!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop();

            if(front.second != i) {
                ++i;
                ans.push_back(level);
                level.clear();
            }
            level.push_back(front.first->val);

            if(front.first->left != nullptr) {
                q.push({front.first->left, front.second + 1});
            }
            if(front.first->right != nullptr) {
                q.push({front.first->right, front.second + 1});
            }
        }
        if(!level.empty()) ans.push_back(level);
        return ans;
    }
};
