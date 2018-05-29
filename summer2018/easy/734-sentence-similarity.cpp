// My solution Use unordered_multimap
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        unordered_multimap<string, string> umm;
        for(auto p : pairs) {
            auto tmp = pair<string, string> (p.second, p.first);
            umm.insert(p);
            umm.insert(tmp);
        }
        bool tf = false;
        for(int i = 0; i < words1.size(); ++i){
            if(words1[i] != words2[i]) {
                auto er = umm.equal_range(words1[i]);
                tf = false;
                for(auto it = er.first; it != er.second; ++it){
                    if(it->second == words2[i]) {
                        tf = true; 
                        break;
                    }
                }
                if(!tf) return false;
            }
        }
        return true;
    }
};



// Unordered_map & unordered_set
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string , unordered_set<string>> dict;
        for (pair<string, string> p : pairs) {
            dict[p.first].insert(p.second);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && !dict[words1[i]].count(words2[i]) && !dict[words2[i]].count(words1[i]))   return false;
        }
        return true;
    }
};



// Vector, find pair in vector
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        for(int i=0;i<words1.size();i++){
            string cur1=words1[i], cur2=words2[i];
            if(cur1==cur2) continue;
            else{
                if(find(pairs.begin(), pairs.end(),pair<string,string>(cur2,cur1))==pairs.end() && find(pairs.begin(), pairs.end(),pair<string,string>(cur1,cur2))==pairs.end()) return false;
            }
        }
        return true;
    }
};
