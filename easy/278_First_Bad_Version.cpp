// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // int firstBadVersion(int n) {
    //    int lower = 1, upper = n, mid;
    //     while(lower < upper) {
    //         mid = lower + (upper - lower) / 2;
    //         if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
    //         else upper = mid;
    //     }
    //     return lower;   /* Because there will alway be a bad version, return lower here */ 
    // }
    int firstBadVersion(int n) {
        long left = 1;
        long right = n;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                right = mid;
                continue;
            } else {
                left = mid + 1;
                continue;
            }
        }
        
        return left;
    }
};