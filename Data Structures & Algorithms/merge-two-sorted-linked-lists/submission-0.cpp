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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode *merge, *previous = nullptr;
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (cur2->val > cur1->val){
            merge = cur1; previous = cur1; cur1 = cur1->next;
        } else {
            merge = cur2; previous = cur2; cur2 = cur2->next;
        }
        while(cur1 != nullptr and cur2 != nullptr){
            if (cur2->val > cur1->val){
                previous->next = cur1;
                previous = cur1;
                cur1 = cur1->next;
            } else {
                previous->next = cur2;
                previous = cur2;
                cur2 = cur2->next;
            }  
        };
        if (!cur1){
            previous->next = cur2;
        } else {
            previous->next = cur1;
        }
        return merge;
    }
};
