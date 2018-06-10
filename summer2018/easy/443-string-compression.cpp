class Solution {
public:
    int intLength(int x, vector<char>& chars, int& i) {
        if (x > 0) {
            int reLen = intLength(x / 10, chars, i) + 1;
            chars[i++] = '0' + x % 10;
            return reLen;
        }
        else return 0;
    }
    
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;
        char past = chars[0];
        int count = 1;
        int totalSum = 0;
        int new_i = 0;
        for (int i = 1; i < n; i++) {
            if (chars[i] == past) count++;
            else {
                chars[new_i++] = past;
                past = chars[i];
                totalSum += count == 1 ? 1 : (1 + intLength(count, chars, new_i));
                count = 1;
            }
        }
        chars[new_i++] = past;
        totalSum += count == 1 ? 1 : (1 + intLength(count, chars, new_i));
        chars.resize(new_i);
        return totalSum;
    }
};


class Solution {
public:
    int compress(vector<char>& a) {
        int i = 0, cnt = 0, t = 0;
        for (int j = 0; j < a.size(); ++j) {
          if (j+1 == a.size() || a[j+1] != a[j]) { // For last or char changed
            int m = t;
            a[t++] = a[j]; // change char value
            if (j >= i + 1) {
                string s = to_string(j-i+1); // Get counter
                for (char c:s) a[t++] = c;   // add counter
            }
            i = j + 1;
            cnt += t-m;
          }
        }
        return cnt;
    }
};
