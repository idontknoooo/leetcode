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
