class MinStack {
private:
    vector<int> m_stack = {}; 
    vector<int>  min_stack={}; 
// 1,2,0
// inf,1,

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_stack.empty()){
            min_stack.push_back(val);
        }
        else if (val <= min_stack.back()){
            min_stack.push_back(val);
        }
        m_stack.push_back(val);
    }
    
    void pop() {
        if (top()==min_stack.back()){
            min_stack.pop_back();;
        }
        m_stack.pop_back();
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};
