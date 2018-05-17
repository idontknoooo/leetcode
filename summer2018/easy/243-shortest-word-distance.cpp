class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pt1 = -1, pt2 = -1;
        int v1 = INT_MAX, v2 = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(words[i] == word1){
                pt1 = i;
            } else if(pt1 >= 0 && words[i] == word2 && (i-pt1)<v1){
                v1 = i - pt1;
            }
            if(words[i] == word2){
                pt2 = i;
            } else if(pt2 >= 0 && words[i] == word1 && (i-pt2)<v2){
                v2 = i - pt2;
            }
        }
        return min(v1, v2);
    }
};
