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
        ListNode *merge, *previous = nullptr;
        if (list1 == nullptr) {return list2;}
        if (list2 == nullptr) {return list1;}

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

    ListNode* mergeKLists_1(vector<ListNode*>& lists) {
        int i = 0 , k =lists.size();
        if (lists.empty()){
            return nullptr;
        }
        int j = k - 1;
        while( i < j ){
            lists[i+1] = mergeTwoLists(lists[i],lists[i+1]);
            i++;
            if (i<j){
                lists[j-1] = mergeTwoLists(lists[j],lists[j-1]);
                j--;
            }
        }

        return lists[i];
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        int i = 0 , k = lists.size();
        vector<ListNode*> res ;

        while(i < k-1){
            res.push_back(mergeTwoLists(lists[i],lists[i+1]));
            i=i+2;
        }
        if (k%2 != 0){
            res.push_back(lists[k-1]);
        };

        int d = res.size();
        i = 0 ; 
        int j = d - 1;
        while( i < j ){
            res[i+1] = mergeTwoLists(res[i],res[i+1]);
            i++;
            if (i<j){
                res[j-1] = mergeTwoLists(res[j],res[j-1]);
                j--;
            }
        }

        return res[i];
    }
};
