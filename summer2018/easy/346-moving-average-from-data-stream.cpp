class MovingAverage {
    int window;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
    }
    
    double next(int val) {
        vec.push_back(val);
        int sum = 0;
        for(int i = vec.size()-1, count = 0; i >= 0 && count < window; --i, ++count)
            sum += vec[i];
        return sum*1.0/min((int)vec.size(), window);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
