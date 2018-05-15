class MinStack {
    vector<long> vec;
    long min_ele;
public:
    /** initialize your data structure here. */
    MinStack() {
       min_ele = INT_MAX; 
    }
    
    void push(int x) {
       vec.push_back(x); 
       min_ele = x<min_ele? x : min_ele; 
    }
    
    void pop() {
       vec.pop_back(); 
       min_ele = *min_element(vec.begin(), vec.end()); 
       if(!vec.size()) min_ele = INT_MAX;
    }
    
    int top() {
       return vec.back();
    }
    
    int getMin() {
       return min_ele; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
