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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        if(!root) return s;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front) s += to_string(front->val);
            else {
                s += "# ";
                continue;
            }
            s += " ";
            q.push(front->left);
            q.push(front->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        string node = "";
        int i = 0;
        while(data[i] != ' '){
            node += data[i];
            i++;
        }
        TreeNode* root = new TreeNode(stoi(node));

        queue<TreeNode*> q; 
        q.push(root);

        i++;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            node = "";
            while(data[i] != ' ') {
                node += data[i];
                i++;
            }
            if(node != "#") {
                TreeNode* left = new TreeNode(stoi(node));
                front->left = left;
                q.push(left);
            }
            i++;
            node = "";
            while(data[i] != ' ') {
                node += data[i];
                i++;
            }
            if(node != "#") {
                TreeNode* right = new TreeNode(stoi(node));
                front->right = right;
                q.push(right);
            }
            i++;
        }
        return root;
    }
};