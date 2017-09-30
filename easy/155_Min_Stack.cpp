// Implemtation using Vector
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    int min_val = INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        if(x<min_val)
            min_val = x;
    }
    
    void pop() {
        bool tf = false;
        if(v.back()==min_val)
            tf = true;
        v.pop_back();
        if(tf) 
            min_val = *min_element(v.begin(), v.end());
        if(!v.size())
            min_val = INT_MAX;
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return min_val;
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

// Implementation using stack (stack is faster than vector)
class MinStack {
	stack<int> a, b;
	// a is the main stack, b store min value (b.pop())
	public:
	/** initialize your data structure here. */
	MinStack() {

	}
	void push(int x) {
		a.push(x);
		if (b.empty() || b.top() >= x)
			b.push(x);
	}
	void pop() {
		int x = a.top();
		a.pop();
		if (b.top() == x) // stored repeat and min
			b.pop();
	}
	int top() {
		return a.top();
	}
	int getMin() {
		return b.top();
	}
};

