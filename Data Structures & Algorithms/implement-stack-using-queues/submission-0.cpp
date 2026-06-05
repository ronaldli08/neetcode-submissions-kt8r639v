class MyStack {
public:

    queue<int> q;
    queue<int> qtemp;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            qtemp.push(front);
        }
        q.push(x);
        while(!qtemp.empty()) {
            int front = qtemp.front();
            qtemp.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int t = top();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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