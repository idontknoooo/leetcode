class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char l1[15] = {'q','w','e','r','t','y','u','i','o','p'};
        char l2[15] = {'a','s','d','f','g','h','j','k','l'};
        char l3[15] = {'z','x','c','v','b','n','m'};
        map<int,int> mp;
        mp.clear();
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            mp.clear();
            for(int j=0; j<words[i].size(); j++){
                int ff=0;
                for(int k=0; k<strlen(l1); k++){
                    if(l1[k]==tolower(words[i][j])) ff++;
                }
                if(ff) {
                    mp[1]++;
                    continue;
                }
                ff=0;
                for(int k=0; k<strlen(l2); k++){
                    if(l2[k]==tolower(words[i][j])) ff++;
                }
                if(ff) {
                    mp[2]++;
                    continue;
                }
                ff=0;
                for(int k=0; k<strlen(l3); k++){
                    if(l3[k]==tolower(words[i][j])) ff++;
                }
                if(ff){
                    mp[3]++;
                    continue;
                }
            }
            if(mp.size()>1) continue;
            ans.push_back(words[i]);
        }
        return ans;
    }
};


class Solution {
public:
        vector<string> findWords(vector<string>& words) {
        // array to record line number for each charactor key on the keyboard
        vector<int> pos = {2/*a*/, 3/*b*/, 3/*c*/, 2/*d*/, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> res;
        std::locale loc;
        for(string word : words)
        {
            int row = pos[tolower(word[0], loc) - 'a'];
            int i = 0;
            for(;i<word.size(); i++)
                if(pos[tolower(word[i], loc) - 'a'] != row) break;
            
            if(i == word.size()) res.push_back(word);
        }
                
        return res;
    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> str = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
        vector<string> res;
        
        for(int i = 0; i < words.size(); i++)
        {
            string s;
            if(str[0].find(words[i][0]) != -1)
                s = str[0];
            else if(str[1].find(words[i][0]) != -1)
                s = str[1];
            else if(str[2].find(words[i][0]) != -1)
                s = str[2];
            
            int j = 0;
            for( j = 0; j < words[i].length(); j++)
                if(s.find(words[i][j]) == string::npos)
                    break;
            
            if(j == words[i].length())
                res.push_back(words[i]);
                
        }
        
        return res;
        
    }
};
