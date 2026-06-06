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
    int i;
    map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        i = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r) return nullptr;
        TreeNode* node = new TreeNode(preorder[i]);
        int mid = m[preorder[i]];
        ++i;
        node->left = build(preorder, inorder, l, mid - 1);
        node->right = build(preorder, inorder, mid + 1, r);
        return node;
    }
};
