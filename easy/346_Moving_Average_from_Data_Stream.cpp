// class MovingAverage {
//     int size = 0;
//     queue<int> q;
//     double ma = 0;
// public:
//     /** Initialize your data structure here. */
//     MovingAverage(int _size) {
//         size = _size;
//     }
    
//     double next(int val) {
//         int tmp = q.size();
//         int _val = 0;
//         if(tmp==size)
//         {
//             _val = q.front();
//             q.pop();
//         }
            
//         q.push(val);
//         ma = (ma*tmp+val-_val)/double(q.size());
//         return ma;
//     }
// };
// class MovingAverage {
// public:
//     /** Initialize your data structure here. */
//     queue<int> q;
//     int size;
//     double sum;
//     MovingAverage(int size) {
//         this->size = size;
//         sum = 0;
//     }
    
//     double next(int val) {
//         sum+=val;
//         q.push(val);
//         int queueSize = (int)q.size();
//         if(queueSize <= size){
//             return sum / queueSize;
//         }else{
//             sum -= q.front();
//             q.pop();
//             return sum / size;
//         }
//     }
// };
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(const int& size) {
        this->dq.clear();
        this->size = size;
    }
    
    double next(const int& val) {
        this->dq.push_front(val);
        if (this->dq.size() < this->size) 
            return double(accumulate(dq.begin(), dq.end(), 0.0)) / double(this->dq.size());
        else
            return double(accumulate(dq.begin(), dq.begin() + this->size, 0.0)) / double(this->size);
    }
private:
    deque<int> dq;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */