class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n - 1;
        --m, --n;
        while(n >= 0 && m >= 0 && total >= 0) {
            if(nums1[m] > nums2[n]) nums1[total--] = nums1[m--];        
            else nums1[total--] = nums2[n--];        
        }
        while(n >= 0) nums1[total--] = nums2[n--];
    }
};
