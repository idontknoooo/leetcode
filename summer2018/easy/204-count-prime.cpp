class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        bool A[n];
        int count = 1;
        memset(A, true, sizeof(A));
        for(int i=3; i<n; i+=2) {
            // For every i, start from i*i since anything before i*i has been cleared, eliminate the multiple of itself, since i will always be odd number then and j starts as an odd number, thus do j += 2*i instead of j += i (which might be even number sometimes)
            if (A[i]) {
                count++;
                for(long long j = (long long)i*i; j<n; j+=2*i) A[j] = false, cout << j << endl;
            }
        }
        return count;
    }
};
