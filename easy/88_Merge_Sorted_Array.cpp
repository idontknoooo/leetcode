
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id1 = m-1, id2 = n-1;
        int i = n+m-1;
		// From most right to left
        while(id1>=0 && id2>=0)
            nums1[i--] = ((nums1[id1]>nums2[id2])? nums1[id1--] : nums2[id2--]);
		// If nums1 have left, let them be where they were
		// If nums2 have left, add them all in the rest left position in nums1
        while(id2>=0) 
            nums1[i--] = nums2[id2--];
    }
};
