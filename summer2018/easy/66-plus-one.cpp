class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        // Handle easy case
        if(digits[size-1]!=9){
            digits[size-1]++;
        } else { // Handle carry case
            int i = size-1;
            while(digits[i]==9)
                digits[i--] = 0;

            // If all the way to beginning, insert 1 at beginning
            if(i<0) digits.insert(digits.begin(), 1); 
            else    digits[i]++; // Else just increament by 1
        }
        return digits;
    }
};
