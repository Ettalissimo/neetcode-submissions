// Definition for singly-linked list.
/*
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* reverseList(ListNode* head) {

        ListNode* current = head;

        vector<ListNode*> m_list = {nullptr} ;
        while (current != nullptr) {

            m_list.push_back(current);

            current = current->next;
        }

        if (!m_list.empty()){
            m_list.erase(m_list.begin());
        }

        for (int i = m_list.size()-1 ; i >= 0 ; i--){
            if (m_list[i] != head){
                m_list[i]->next = m_list[i-1];
            } else {
                m_list[i]->next = nullptr;
                head = m_list[m_list.size()];
            }
        }
        
        return head;
    };
*/

class Solution {
public:
    /*ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* next = nullptr;

        while (current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;

    };*/
    ListNode* helper(ListNode* head, ListNode * tail){
            if(head == tail ){
                return head;
            };
            ListNode* new_head = head->next;
            ListNode* n_tail = tail->next;
            tail->next = head;
            head->next = n_tail;
            return helper(new_head,tail); 
    };

    ListNode* reverseList(ListNode* head){
        if(!head){
            return head;
        }
        ListNode* tail = head, *prev;

        while(tail){
            prev = tail;
            tail = tail->next;
        };
        tail = prev;
        return  helper(head,tail);
    }
};
