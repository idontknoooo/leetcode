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

// Intuitive way to express digits[i]%=10
vector<int> plusOne(vector<int>& digits) {

	for(int i = digits.size()-1; i >= 0; --i){
		if(digits[i]+1==10)
			digits[i] = 0;
		else{
			digits[i]++;
			break;
		}
	}
	if(!digits[0]) digits.insert(digits.begin(), 1);
	return digits;

}