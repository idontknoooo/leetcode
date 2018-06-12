// My solution 6ms
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x || y) {
            int tmp = (x&1) ^ (y&1);
            if(tmp) ans += 1;
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
};


// 4ms less operations
class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int r = x ^ y;
        int b = 0;
        while(r) {
            if(r & 1) b++;
            r = (r >> 1);
        }
        return b;
    }
};
