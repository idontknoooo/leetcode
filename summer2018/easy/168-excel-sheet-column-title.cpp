class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0) {
            int tmp = (n-1) % 26;
            ans += 'A' + tmp;  // add to back is faster
            n = (n-1) / 26;
        }
        reverse(ans.begin(), ans.end()); // then reverse the list
        return ans;
    }
};
