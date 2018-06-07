class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        while(k-->0){
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
        
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
    
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums.begin(), nums.end() - k);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.end() - k, nums.end());

        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.end());
    }
};
