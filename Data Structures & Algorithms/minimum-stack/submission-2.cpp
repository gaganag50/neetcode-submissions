class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int x = INT_MAX;
        if(!min_stk.empty()){
            x = min_stk.top();
        }
        if(val < x) {
            min_stk.push(val);
        } else {
            min_stk.push(x);
        }
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        int x = stk.top();
        return x;
    }
    
    int getMin() {
        return min_stk.top();
    }
};
