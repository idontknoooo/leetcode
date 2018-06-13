// https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ret = 0;
        while (pow(minutesToTest / minutesToDie + 1, ret) < buckets) ret++;
        return ret;
    }
};
