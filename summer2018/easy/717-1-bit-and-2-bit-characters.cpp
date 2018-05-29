// My solution
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i = 0; i < bits.size(); ) {
            if(!bits[i] && bits.size()-1 == i) return true;
            else if(bits[i]==1) i += 2;
            else i++;
        }
        return false;
    }
};
