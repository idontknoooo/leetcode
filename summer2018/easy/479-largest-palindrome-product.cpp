class Solution {
public:
    int largestPalindrome(int n) {

        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = upper / 10;
        for(int i = upper; i > lower; i--) {
            string t = to_string(i);
            long p = stol(t + string(t.rbegin(), t.rend())); // Make palindrome
            for(long j = upper; j * j >= p; j--) { // j must be long, if j*j < p, then p/j must be more than upper which is not satisfied
                if (p % j == 0)
                    return p % 1337;
            }
        }
    }
};

// Slow
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n-1);
        for (int i = upper; i >= lower; i--) {
            long cand = buildPalindrome(i);
            for (long j = upper; j*j >= cand; j--) {
                if (cand % j == 0 && cand / j <= upper) {
                    return cand % 1337;
                }
            }
        }
        return -1;
    }
    
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
};

