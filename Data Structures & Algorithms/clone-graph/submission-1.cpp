/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> newPath;

        queue<Node*> q;
        q.push(node);

        newPath[node] = new Node(1);

        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            for(Node* next:front->neighbors) {
                if(!newPath[next]){
                    newPath[next] = new Node(next->val);
                    q.push(next);
                }
                newPath[front]->neighbors.push_back(newPath[next]);
            }
        }


        return newPath[node];
    }
};
