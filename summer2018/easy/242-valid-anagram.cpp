class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um1, um2;
        for(char c : s)
          um1[c]++;
        for(char c : t)
          um2[c]++;
        return um1 == um2;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        std::vector<int> chars(256,0);
        for(int i=0;i<s.size();i++)
        {
            chars[s.at(i)]++;
            
        }
        for(int j=0;j<t.size();j++)
        {
            chars[t.at(j)]--;
        }
        for(int k=0;k<chars.size();k++)
        {
            
            if(chars[k]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
