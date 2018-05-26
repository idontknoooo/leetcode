// my solution 6 ms
class Solution {
public:
    bool checkRecord(string s) {
        bool a = !(s.find("LLL") != string::npos);
        bool b = !(count(s.begin(), s.end(), 'A') > 1);
        return a && b;
    }
};


// 4ms
class Solution {
public:
    bool checkRecord(string& s) {
        int count = 0, cnt = 0;
        for(char& c : s){
            if(c=='L'){
                if(++cnt>2) return false;
            }else if(c == 'A'){
                if(++count==2) return false;
                cnt = 0;
            }else cnt = 0;
        }
        return true;
    }
};
