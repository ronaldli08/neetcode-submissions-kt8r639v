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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* merged = new ListNode();
        ListNode* cur = merged;
        while(1) {
            int minI = -1;
            for(int i = 0; i < n; ++i) {
                if(lists[i] != nullptr && (minI == -1 || lists[i]->val < lists[minI]->val)){
                    minI = i;
                }
            }
            if(minI == -1) {
                break;
            }
            cur->next = lists[minI];
            cur = cur->next;
            lists[minI] = lists[minI]->next;
        }
        return merged->next;
    }
};
