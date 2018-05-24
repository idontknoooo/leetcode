class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string rst;
        int len = S.size();
        int times = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (S[i] == '-') {
                continue;
            } else {
                if (!('0' <= S[i] && S[i] <= '9')) {
                    S[i] = toupper(S[i]);     
                }
                if (times == K) {
                    times = 0;
                    rst.push_back('-');
                }
                rst.push_back(S[i]);
                ++times;
            }
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};


class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string rlt = "";
        int count = 0;
        for(int i = S.length()-1; i >= 0; i -= 1){
            string tmp = "";
            if(isalnum(S[i])){
                ++count;
                if(count==1){
                    tmp += "-";
                }
                if(isalpha(S[i]))
                    tmp = (char)toupper(S[i]) + tmp;
                else
                    tmp = S[i] + tmp;
                rlt = tmp + rlt;
                if(!(count%K)){
                    count = 0;
                }
            }
        }
        return rlt.substr(0, rlt.length()-1);
    }
};
