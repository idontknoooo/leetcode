class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Find shortest string
        if(strs.size() == 0) return ""; 
        string s   = "";
        int    len = INT_MAX; 
        for(int i = 0; i < strs.size(); ++i){
            if(strs[i].length()<len){
                len = strs[i].length();
                s   = strs[i];
            }
        }
        // Append common char to string
        string result = ""; 
        char tmp = ' ';
        for(int i = 0; i < len; ++i){
            tmp = strs[0][i];
            for(int j = 0; j < strs.size(); ++j){
                if(tmp != strs[j][i])
                    return result;
            }
            result += tmp;
        }
        return result;
    }
};
