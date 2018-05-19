class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for(int i = p.size(); i < s.size(); ++i) 
        {
             // window extends one step to the right. counter for s[i] is incremented 
            ++sv[s[i]-'a'];
            
            // since we added one element to the right, 
            // one element to the left should be forgotten. 
            //counter for s[i-p.size()] is decremented
            --sv[s[i-p.size()]-'a']; 

            // if after move to the right the anagram can be composed, 
            // add new position of window's left point to the result 
            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(256,0), sv(256,0), res;
        if(s.size() < p.size())
           return res;
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if(pv == sv)
           res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]];
            --sv[s[i-p.size()]];
            if(pv == sv)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};



class Solution {
    vector<int> count;
    int non_zero;
    vector<int> res;
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        
        count = vector<int>(26, 0);
        non_zero = 0;
        res = vector<int>();
        
        for (auto c : p) {
            update(c - 'a', 1);
        }
        
        for (int i = 0; i < np; i++) {
            update(s[i] - 'a', -1);
        }
        
        if (non_zero == 0) {
            res.push_back(0);
        }
        
        for (int i = np; i < ns; i++) {
            update(s[i - np] - 'a', 1);
            update(s[i] - 'a', -1);
            
            if (non_zero == 0)  {
                res.push_back(i - np + 1);
            }
        }
        
        return res;
    }
    
    void update(int index, int delta) {
        int before = count[index];
        int after = before + delta;
        count[index] = after;
        
        if (before == 0) {
            non_zero++;
        }
        
        if (after == 0) {
            non_zero--;
        }
    }
};
