class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        
        bool flag = false;
        if(num < 0) num = -num, flag = true;
            
        string ans = "";
        while(num != 0){
            ans += to_string(num % 7);
            num /= 7;
        }
        
        reverse(ans.begin(), ans.end());
        return flag? "-" + ans : ans;
    }
};
