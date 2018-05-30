// My solution 3ms beat 90%
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, last = 0, cur = 0, space = 0;
        for(int i = 0; i < S.length(); ){
            space = widths[S[i] - 'a'];
            if(cur + space > 100) {
                ++line;
                cur = 0;
            } else {
                cur += space;
                ++i;
            }
        }
        return {line, cur};
    }
};
