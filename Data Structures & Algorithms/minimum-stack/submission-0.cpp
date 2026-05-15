class MinStack {
public:

    stack<int> s;
    stack<int> minval;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!minval.empty())
            minval.push(min(val, minval.top()));
        else
            minval.push(val);
    }
    
    void pop() {
        s.pop();
        minval.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minval.top();
    }
};
