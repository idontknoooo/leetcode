// 4ms
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i=0;i<nums.size();i++){
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), comp);
        string result;
        for(int i=0;i<str.size();i++){
            result += str[i];
        }
        while(result[0]=='0'&&result.length()>1){
            result.erase(result.begin());
        }
        return result;
    }
private:
    static bool comp(string& s1, string& s2){
        return s1+s2>s2+s1;//very important!!
    }
};

// 5ms
class Solution {
public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> s;
        for(int i = 0 ; i < nums.size(); i++) {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(), s.end(), compare);
        for(int i = 0 ; i < s.size(); i++) 
            ans += s[i];
        int i = 0 ;
        while(ans[i] == '0' && i + 1 < ans.length()) i++;
        return ans.substr(i);
    }
};
