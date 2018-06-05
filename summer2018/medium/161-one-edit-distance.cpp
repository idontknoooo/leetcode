// 4ms
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=(int)s.size(), n=(int)t.size();
        if (m<n) return isOneEditDistance(t, s);
        if (m-n>1) return false;
        for (int i=0; i<n; ++i) {
            if (s[i] != t[i]) {  
                if (m==n) return s.substr(i+1)==t.substr(i+1);
                return s.substr(i+1)==t.substr(i);
            }
        } 
        return m-n==1;
    }
};

// 4ms
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int i = 0, j = 0;
        int M = s.length();
        int N = t.length();
        
        for (i = 0, j = 0; i < M && j < N; ++i, ++j) {
            if (s[i] != t[j]) {
                if (i == M-1 && j == N-1) {
                    // Only last charater differs
                    return true;
                }
                
                string s_at_i = s.substr(i, M-i);
                string t_at_j = t.substr(j, N-j);
                string s_at_i_plus_1 = s.substr(i+1, M-(i+1));
                string t_at_j_plus_1 = t.substr(j+1, N-(j+1));
                
                
                if ((i == M-1 && (s_at_i == t_at_j_plus_1)) || // Add char at s[i] from t[i]
                    (j == N-1 && (t_at_j == s_at_i_plus_1))) { // Del char at s[i] 
                    return true;
                }
                
                /* Here we know that, s and t both have 1 or more charaters left after the differing char */
                if ((s_at_i == t_at_j_plus_1) || // Add char at s[i] from t[i] or
                    (t_at_j == s_at_i_plus_1) || // Del char at s[i] or
                    (s_at_i_plus_1 == t_at_j_plus_1)) { // Replace char at s[i] with t[i]
                        return true;
                }
                return false;
            }
        }
        
        // Here we know that all the charaters match and one or both of the string is/are exhausted.
        // If only one of the strings has exhausted, then the remaining characters left in the 
  // non-exhausted string should be 1.
        if ((i == M && j == N-1) || (j == N && i == M-1)) {
            return true;
        } 
        
        return false;
    }
};

