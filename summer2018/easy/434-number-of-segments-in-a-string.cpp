class Solution {
public:
    int countSegments(string s) {
        bool tf = false;
        int count = 0;
        for(int i = 0; i < s.length(); ++i){
            if(!tf && s[i]!=' ')     tf = true, ++count;
            else if(tf && s[i]==' ') tf = false;
        }
        return count;
    }
};
