class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s(candies.begin(), candies.end());
        return s.size()>candies.size()/2? candies.size()/2 : s.size();
    }
};


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> um;
        for(int c : candies)
            um[c] = 1;
        if(um.size() > candies.size()/2) return candies.size() / 2;
        else return um.size();
    }
};


// faster solution beat 92% using bitset
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int len = candies.size();
        bitset<200001> bs;
        int cnt = 0;
        for(int i = 0; i < len; i++){
            cnt += !bs.test(candies[i] + 100000); // Count unset bit (avoid repeat)
            bs.set(candies[i] + 100000); // Set bit
        }
        return min(cnt, len / 2);
    }
};
