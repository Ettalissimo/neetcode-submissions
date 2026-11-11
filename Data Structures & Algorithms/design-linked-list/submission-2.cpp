class MyLinkedList {
public:
    // int val;
    // MyLinkedList * next, * prev;
    
    struct Node{
        int val;
        Node * next;
        Node * prev;
        Node(int x, Node* n, Node* p): val(x), next(n), prev(p) {}
        Node(int x, Node* n): val(x), next(n), prev(nullptr) {}
        Node(int x): val(x), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr, *temp_prev, *temp_next;
    Node* tail = nullptr;
    int size = 0;

    MyLinkedList() {
        
    }

    int get(int index) {
        if (index > size-1 or index < 0){
            return -1;
        }

        Node * index_ptr = head;
        for (int i = 0; i<index; ++i){
                index_ptr = index_ptr->next;
        }

        return index_ptr->val;
    };
    
    void addAtHead(int val) {
        if (!head){
            head = new Node(val);
            tail = head;
        } else{
            Node * node = new Node(val,head);
            head = node;
            head->next->prev = head;
        };
        size++;
        std::cout << "addhead executed"<< std::endl;
    };
    
    void addAtTail(int val) {
        if(!tail){
            head = new Node(val);
            tail = head;
        }else{
            Node * node = new Node(val,nullptr,tail);
            tail->next = node;
            tail = node;
        };
        size++;
        std::cout << "addTail executed"<< std::endl;

    };
    
    void addAtIndex(int index, int val) {
        if (index > size or index < 0){
            return ;
        }

        if (index == 0){
            addAtHead(val);  return;
            std::cout << "addhead in addIndex executed"<< std::endl;

        }
        if (index == size){
            addAtTail(val);  return;
            std::cout << "addTail in addIndex executed"<< std::endl;

        }

        Node * index_ptr = head;
        for (int i = 0; i<index; ++i){
                index_ptr = index_ptr->next;
        }

        Node* node = new Node(val, index_ptr ,index_ptr->prev);
        index_ptr->prev->next = node;
        index_ptr->prev = node;
        std::cout << "addIndex executed"<< std::endl;
        size++;
    };
    
    void deleteAtIndex(int index) {
        if (index > size-1 or index < 0){
            return ;
        }
        Node * index_ptr = head;
        for (int i = 0; i<index; ++i){
                index_ptr = index_ptr->next;
        }
        if (index == 0){
            head = index_ptr->next;
            index_ptr->next->prev = nullptr; size--; 
            std::cout << "delete executed"<< std::endl;
            return;
        }
        if (index == size-1){
            tail = index_ptr->prev;
            tail->next = nullptr; size--; 
            std::cout << "delete executed"<< std::endl;
            return;
        } 
        
        index_ptr->prev->next = index_ptr->next;
        index_ptr->next->prev = index_ptr->prev;
        
        size--;
        std::cout << "delete executed"<< std::endl;
        
    };
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */