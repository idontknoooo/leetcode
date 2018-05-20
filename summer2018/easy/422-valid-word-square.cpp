class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        if (m == 0) return true;
        int n = 0;
        
        for (int i = 0; i < m; i++) {
            int j = i;
            int n = words[i].size();
            int size = max(m, n);
            
            for (int j = i; j < size; j++) {
                char a, b;
                if (j < words[i].size())    a = words[i][j];
                else    a = ' ';
                if (i < words[j].size() && j < m)    b = words[j][i];
                else    b = ' ';
                if (a != b) return false;
            }
        }
        
        return true;
    }
};

class Solution {
public:
    string getVertical(vector<string>& words,int col){
        string s="";
        for(int i=0;i<words.size();i++) if(col<words[i].size()) s.push_back(words[i][col]);
        return s;
    }
    
    bool validWordSquare(vector<string>& words) {
        for(int i=0;i<words.size();i++) if(words[i]!=getVertical(words,i)) return false;
        return true;
    }
};
