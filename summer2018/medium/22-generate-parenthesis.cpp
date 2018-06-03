// 2ms solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        add(ret, "", n, n);
        return ret;
    }
    void add(vector<string> & ret, string s, int left, int right){
        if(left == 0 && right == 0){
            ret.push_back(s);
            return; 
        }
        if(left > 0)
            add(ret, s + "(",left-1, right);
        if(right > left)
            add(ret, s + ")", left, right-1);
    }
};


// My super slow solution 285ms
class Solution {
public:
    queue<string> makeP(queue<string> q) {
        queue<string> re;
        while(q.size()) {
            string s = q.front();
            q.pop();
            for(int i = 0; i < s.length()-1; ++i) {
                string copy = s;
                copy = copy.substr(0, i) + "()" + copy.substr(i, s.length()-i);
                re.push(copy);
            }
        }
        return re;
    }
        
    vector<string> generateParenthesis(int n) {
        queue<string> q;
        q.push("()");
        while(--n) {
            q = makeP(q);
        }
        set<string> vec;
        while(q.size()) {
            vec.insert(q.front());
            q.pop();
        }
        return vector<string> (vec.begin(), vec.end());
    }
};
