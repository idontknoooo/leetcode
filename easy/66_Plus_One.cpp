class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		// It's not intuitive but, carry is 'true' at beginning
        bool carry = true;
        for(int i = digits.size()-1; i >= 0 && carry; --i)
            carry = !(++digits[i]%=10);
        
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
