/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        unordered_map<Node*, Node*> m;
        Node* og = head;

        Node* newhead = new Node(head->val);
        Node* cur = newhead;
        newhead->random = head->random;

        m[head] = newhead;
        head = head->next;
        while (head) {
            cur->next = new Node(head->val);
            cur = cur->next;
            m[head] = cur;
            //cur->random = head->random;
            head = head->next;
            
        }
        cur = newhead;
        head = og;

        m[nullptr] = nullptr;



        while (cur) {
            cur->random = m[head->random];
            head = head->next;
            cur = cur->next;
        }

        return newhead;
    }
};
