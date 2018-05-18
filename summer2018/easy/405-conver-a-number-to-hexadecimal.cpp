class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        string hex = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string ret="";
        for(int i=0;i<8 && num!=0;i++)
        {
            int temp  = num & 15;
            ret      += hex[temp];
            num     >>= 4; // num /= 16 but >> to hand negative
        }
        reverse(ret.begin(),ret.end());
        
        return ret;
        
    }
};
