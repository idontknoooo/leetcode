// 150 ms design
class TwoSum {
    unordered_multiset<int> nums;
public:
    void add(int number) {
        nums.insert(number);
    }
    bool find(int value) {
        for (int i : nums) {
            int count = i == value - i ? 1 : 0; // handle 0-0==0
            if (nums.count(value - i) > count) {
                return true;
            }
        }
        return false;
    }
};

// 39 ms Design
class TwoSum {
private:
    unordered_map<int, int> imap;
    int low, high;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        imap.clear();
        low=INT_MAX, high=INT_MIN;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        imap[number]++;  // Key is number, value is the frequency
        low=min(low, number);
        high=max(high, number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if((low<<1)>value || (high<<1)<value)return false;
        for(auto e:imap)
        {
            if(2*e.first==value)
            {
                if(e.second>=2)return true;
            }
            else if(imap.find(value - e.first)!=imap.end())return true;
        }
        return false;
    }
};
/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */