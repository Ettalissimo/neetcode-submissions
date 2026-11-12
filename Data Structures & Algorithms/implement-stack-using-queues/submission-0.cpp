class MyStack {
private:
    deque<int> my_stack ;
    int size;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        my_stack.push_back(x);
    }
    
    int pop() {
        // my_stack.pop_back();
        int val = top();
        deque<int> nd_stack(my_stack.begin() ,my_stack.end()-1);
        my_stack = nd_stack;
        return val;

    }
    
    int top() {
        // my_stack.top();
        // size = my_stack.size();
        deque<int> trd_stack(my_stack.end()-1 ,my_stack.end());
        return trd_stack.front();
    }
    
    bool empty() {
        return my_stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */