class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int val = 0;
        if(q.size()<=1) {
            val = q.front();
            q.pop();
            return val;
        }
        val = q.back();
        while(q.size()>1){
            tmp.push(q.front());
            q.pop();
        }
        while(!q.empty()) q.pop();
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
