// 28ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> toVisit1, toVisit2, temp;
        if(dict.count(endWord) == 0) return 0;
        dict.erase(endWord);
        toVisit1.insert(beginWord);
        toVisit2.insert(endWord);
        int dist=1;
        while(!toVisit1.empty()){
            temp.clear();
            for(string word: toVisit1){
                for(char& c: word){
                    const char origin = c;
                    for(int i=0; i<26; ++i){
                        c = 'a' +i;
                        if(toVisit2.count(word)>0) return dist+1;
                        if(dict.count(word)>0){
                            dict.erase(word);
                            temp.insert(word);
                        }
                    }
                    c = origin;
                }
            }
            toVisit1 = (temp.size()>toVisit2.size())? toVisit2:temp;
            toVisit2 = (temp.size()>toVisit2.size())? temp:toVisit2;
            dist++;
        }
        return 0;
    }
};
