class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            // Comput sum of last digits and carry
			// '1' - '0' == 1 -> ascii
            c += i >= 0 ? a[i--] - '0' : 0; 
            c += j >= 0 ? b[j--] - '0' : 0;
			// When both above are 1s and c==1, then c==3
            // If current digit sum is 1 or 3, add 1 to result
            s = char(c % 2 + '0') + s;
            // Compute carry
            c /= 2; // carry if c == 2
        }
        
        return s;
    }
};
