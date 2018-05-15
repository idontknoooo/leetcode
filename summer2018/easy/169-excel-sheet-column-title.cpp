class Solution {
public:
    string convertToTitle(int n) {
        vector<string> vec = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int tmp = 0;
        if(n > 0) tmp = (n-1)%26;
        else return "";
        return convertToTitle((n-1)/26) + vec[tmp];
    }
};


// Simplified same code
class Solution {
public:
    string convertToTitle(int n) {
        return n>0? convertToTitle((n-1)/26) + (char)('A' + (n-1)%26) : "";
    }
};
