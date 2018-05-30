// Think of the original S as root of tree
// The alternation of first letter being root->left & root->right
// Only push them when they reach to the end
class Solution {
public:
    
    vector<string> letterCasePermutation(string S) {
        vector<string> vs;
        helper(vs,S,0);
        return vs;
    }
    
    void helper(vector<string>& vs,string& S,int p){
        if(p == S.size()) {
            vs.push_back(S);
            return ;
        }
        if(S[p] >= '0' && S[p] <= '9') helper(vs,S,p+1);
        else if(S[p] >= 'a' && S[p] <= 'z'){
            helper(vs,S,p+1);
            S[p] += 'A'-'a';
            helper(vs,S,p+1);
        }
        else if(S[p] >= 'A' && S[p] <= 'Z'){
            helper(vs,S,p+1);
            S[p] += 'a'-'A';
            helper(vs,S,p+1);
        }
    }
};
