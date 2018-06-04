// 25ms permutation
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int PRIMES[] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
        unordered_map<int, vector<string>> dic;
        for (const auto& s: strs) {  // Use prime as a way to specify key
            int k = 1;
            for (const auto c: s) {
                k *= PRIMES[c-'a'];
            }
            dic[k].push_back(s);
        }
        for ( auto it = dic.begin(); it != dic.end(); ++it ) {
            result.push_back(it->second);
        }
        return result;
    }
};

// My solution 29ms hashmap
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > um;
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            um[tmp].push_back(strs[i]);
        }
        vector<vector<string> > ans(um.size());
        int i = 0;
        for(auto p : um) {
            ans[i++] = p.second;
        }
        return ans;
    }
};
