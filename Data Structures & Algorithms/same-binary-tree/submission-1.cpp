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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        queue<TreeNode*> q1;
        queue<TreeNode*>q2;
        if(p)q1.push(p);
        if(q)q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* front1 = q1.front();
            TreeNode* front2 = q2.front();
            q1.pop();
            q2.pop();

            if(front1->val != front2->val) return false;
            if(front1->left) {
                if(front2->left) {
                    q1.push(front1->left);
                    q2.push(front2->left);
                }
                else {
                    return false;
                }
            }
            else {
                if(front2->left) {
                    return false;
                }
            }
            if(front1->right) {
                if(front2->right) {
                    q1.push(front1->right);
                    q2.push(front2->right);
                }
                else {
                    return false;
                }
            }
            else {
                if(front2->right) {
                    return false;
                }
            }
        }
        if(q1 != q2) return false;
        else return true;
    }
};
