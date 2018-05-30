// My solution 13ms, find the min(left_distance, right_distance)
class Solution {
public:
    int find_next(int pos, char C, string S) {
        for(int i = pos; i <= S.length(); ++i) 
            if(S[i]==C) return i;
        return -1;
    }
    vector<int> shortestToChar(string S, char C) {
        int slow = S.find(C); 
        int fast = find_next(slow+1, C, S);
        vector<int> vec;
        for(int i = 0; i < S.length(); ++i) {
            //if(i < slow) {
            //    vec.push_back(slow - i);
            //} else if (i < fast && i >= slow) {
            //    vec.push_back(min(abs(slow-i), abs(fast-i)));
            //} else {
            //    if(fast != -1) {
            //        slow = fast;
            //        fast = find_next(i, C, S);
            //    }
            //    vec.push_back(min(abs(slow-i), abs(fast-i)));
            //}
            if(i >= fast && fast != -1) {
                slow = fast;
                fast = find_next(i, C, S);
            }
            if(fast != -1) vec.push_back(min(abs(slow-i), abs(fast-i)));
            else vec.push_back(abs(slow-i));
        }
        return vec;
    }
};
