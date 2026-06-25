/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        ListNode* cur = head;
        stack<ListNode*> s;
        while(cur) {
            s.push(cur);
            cur = cur->next;
        }
        for(int i = 0; i < n; ++i) {
            cur = s.top();
            s.pop();
        }
        if(s.empty()) {
            return cur->next;
        }
        else {
            s.top()->next = cur->next;
            return head;
        }
    }
};
