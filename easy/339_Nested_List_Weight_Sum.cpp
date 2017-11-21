/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// class Solution {
// public:
//     int depthSum(vector<NestedInteger>& nestedList) {
//         return depthSumHelper(nestedList, 1);
//     }
    
//     int depthSumHelper(vector<NestedInteger>& nestedList, int depth){
//         int ans = 0;
//         for(auto nl: nestedList){
//             if(nl.isInteger()) ans += depth * nl.getInteger();
//             else
//                 ans += depthSumHelper(nl.getList(), depth + 1);
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        helper(nestedList);
        return sum;
    }
private:
    int sum=0;
    int helper(vector<NestedInteger>& nestedList) {
        int tmp=0;
        for (NestedInteger NI:nestedList) {
            if (NI.isInteger()) tmp+=NI.getInteger();
            else tmp+=helper(NI.getList());
        }
        // cout << tmp << endl;
        sum+=tmp;
        return tmp;
    }
};