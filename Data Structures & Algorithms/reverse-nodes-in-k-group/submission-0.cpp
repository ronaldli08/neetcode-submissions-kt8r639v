class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = head;

        ListNode* prevTail = dummy;

        while(1) {
            if(cur == nullptr) return dummy->next;
            ListNode* node = cur;
            for(int i = 0; i < k; i++) {
                if(cur == nullptr) {
                    return dummy->next;
                }
                cur = cur->next;
            }
            ListNode* noden = cur;
            ListNode* prevv = cur;
            ListNode* curr = node;
            while(curr != noden) {
                ListNode* nxt = curr->next;
                curr->next = prevv;
                prevv = curr;
                curr = nxt;
            }
            prevTail->next = prevv;
            prevTail = node;
            cur = noden;
        }
        return dummy->next;
    }
};