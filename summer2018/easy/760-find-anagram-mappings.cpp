// My solution 6ms
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> um;
        for(int i = 0; i < B.size(); ++i)
            um[B[i]] = i;
        
        vector<int> vec;
        for(int i : A)
            vec.push_back(um[i]);
        
        return vec;
    }
};
