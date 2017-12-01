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
		if (b.top() == a.top()) // stored repeat and min
			b.pop();
        a.pop();
	}
	int top() {
		return a.top();
	}
	int getMin() {
		return b.top();
	}
};
// Best Method
// Stack method
class MinStack {
private:
    // if top negative, then min_value was changed, can restore old_min = curr_min - top
    // if top non-negative, then min_value was same, but can restore curr_value = curr_min + top
    stack<long> st;
    long curr_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        curr_min = 0;
    }
    
    void push(int x) {
        if (st.empty()) {
            // special handling for first element
            st.push(0);
            curr_min = x;
        } else {
            // Store information of minimun number in each entry
            // subtract all number just to make sure they are all positive, 
            // except for current_min(negative)
            long top = x - curr_min;
            st.push(top);
            if (top < 0) {
                curr_min = x;
            }
        }
    }
    
    void pop() {
        long top = st.top();
        if (top < 0) {
            curr_min -= top;
        }
        st.pop();
    }
    
    int top() {
        long top = st.top();
        if (top < 0) {
            return curr_min;
        }
        return curr_min + top;
    }
    
    int getMin() {
        return curr_min;    
    }
};