// my solution 10ms
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> um;
        for(char c : J) um[c] = 1;
        int count = 0;
        for(char c : S) if(um[c]) ++count;
        return count;
    }
};

// 8ms
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // array is faster than hash map for small size array
        int count[128]={0};
        int res = 0;
        for (int i = 0; i < J.size(); i++) {
            count[J[i]]++;
        }
        for (int i = 0; i < S.size(); i++) {
            if ((count[S[i]]) > 0) {
                res++;
            }
        }
        return res;
    }
};
