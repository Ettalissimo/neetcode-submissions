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
        //ListNode *list1 = list1, *list2 = list2;
        ListNode *merge, *previous = nullptr;
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list2->val > list1->val){
            merge = list1; previous = list1; list1 = list1->next;
        } else {
            merge = list2; previous = list2; list2 = list2->next;
        }
        while(list1 != nullptr and list2 != nullptr){
            if (list2->val > list1->val){
                previous->next = list1;
                previous = list1;
                list1 = list1->next;
            } else {
                previous->next = list2;
                previous = list2;
                list2 = list2->next;
            }  
        };
        if (!list1){
            previous->next = list2;
        } else {
            previous->next = list1;
        }
        return merge;
    }
};
