class MyQueue {
    stack<int> s;
    stack<int> backup;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        front = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty()) front = x;
        while(!s.empty()){
            backup.push(s.top());
            s.pop();
        }    
        s.push(x);
        while(!backup.empty()){
            s.push(backup.top());
            backup.pop();
        }    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = s.top();
        s.pop();
        if(!s.empty())
            front = s.top();
        else front = 0;
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
