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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        ListNode* sec = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(sec != nullptr) {
            ListNode* tmp = sec->next;
            sec->next = prev;
            prev = sec;
            sec = tmp;
        }

        ListNode* first = head;
        sec = prev;
        while(sec!= nullptr) {
            ListNode* t1 = first->next;
            ListNode* t2 = sec->next;
            first->next = sec;
            sec->next = t1;
            first = t1;
            sec = t2;
        }

    }
};
