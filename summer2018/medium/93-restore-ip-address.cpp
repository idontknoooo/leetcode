// 4ms
class Solution {
public:
    /**
    * @param s: the IP string
    * @return: All possible valid IP addresses
    */
    vector<string> restoreIpAddresses(string &s) {
        // write your code here
        vector<string> results;
        string result;

        backtrace(results, result, s, 0, 0);
        return results;
    }

    void backtrace(vector<string> &results, string &result, string &s, int start, int step) {
        if(start == s.size() && step == 4) {
            result.resize(result.size() - 1);
            results.push_back(result);
            return;
        }
        if(s.size() - start > (4 - step) * 3) {
            return;
        }
        if(s.size() - start < (4 - step)) {
            return;
        }
        int num = 0;
        for(int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if(num <= 255) {
                result += s[i];
                string temp = result + '.';
                backtrace(results, temp, s, i + 1, step + 1);
            }
            if(num == 0) {
                break;
            }
        }
    }
};

// iterative: exhaustive search
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
};
