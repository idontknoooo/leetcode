// My solution 22ms
class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n==2) return true;
        if(!(n%2)) return false;
        for(int i = 3; i <= sqrt(n); i+=2) 
            if(!(n%i)) return false;
        return true;
    }
    int setBits(int n) {
        int count = 0;
        while(n > 0) {
            if(n & 1) ++count;
            n >>= 1;
        }
        return count;
    }
    int countPrimeSetBits(int L, int R) {
        int count = 0, bits = 0;
        for(int i = L; i <= R; ++i) {
            bits = setBits(i);
            if(isPrime(bits)) ++count;
        }
        return count;
    }
};

// 7ms
static int x = [](){std::ios::sync_with_stdio(false); cin.tie(NULL); return 0;}();

class Solution {

public:
  int countPrimeSetBits(int L, int R) {
    int k = 0;
    for (int x = L - 1; x; k += x & 1, x >>= 1) {}
    int n = 0;
    for (int i = L; i <= R; ++i) {
      ++k;
      for (int x = i; !(x & 1); x >>= 1, --k) {}
      n += k == 2 || k == 3 || k == 5 || k != 1 && k % 2 && k % 3 && k % 5;
    }
    return n;
  }
};

// 9ms
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0, hash[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
        for (int i = L; i <= R; i++) {
            bitset<20> b(i);
            if(hash[b.count()]) cnt++;
        }
        return cnt;
    }
};
