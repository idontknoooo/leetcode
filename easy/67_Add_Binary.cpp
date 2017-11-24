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
string addBinary(string a, string b){

    string s = "";
    bool carry = 0;
    int pa = a.length()-1, pb = b.length()-1;
    while(pa >= 0 || pb >= 0){
        int tmp = 0;
        int va = pa>=0? (a[pa--]-'0') : 0;
        int vb = pb>=0? (b[pb--]-'0') : 0;
        tmp = va+vb;

        if(carry) tmp++;
        carry = tmp/2;
        s = to_string(tmp%2) + s;
    }
    if(carry) s = '1'+s;
    return s;
}