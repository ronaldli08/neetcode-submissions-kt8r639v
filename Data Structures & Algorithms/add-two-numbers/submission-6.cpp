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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* cur = sum;
        bool carry = false;
        while(l1 && l2) {
            int add = l1->val + l2->val + (carry ? 1 : 0);
            if(add >= 10) {
                carry = true;
                add -= 10;
            }
            else carry = false;
            cur->next = new ListNode(add);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 && !l2) {
            while(l1) {
                int add = l1->val + (carry ? 1 : 0);
                if(add >= 10) {
                    carry = true;
                    add -= 10;
                }
                else carry = false;
                cur->next = new ListNode(add);
                cur = cur->next;
                l1=l1->next;
            }
        }
        else if(!l1 && l2) {
            while(l2) {
                int add = l2->val + (carry ? 1 : 0);
                if(add >= 10) {
                    carry = true;
                    add -= 10;
                }else carry = false;
                cur->next = new ListNode(add);
                cur = cur->next;
                l2=l2->next;
            }
        }
        if(carry) {
            cur->next = new ListNode(1);
        }
        return sum->next;
    }
};
