// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int mid = (high-low)/2+low;
        int re = guess(mid);
        //if(!re) return mid;
        while(re!=0 && low < high){
            if(re==-1) high = mid;
            else low = mid+1;
            mid = (high-low)/2+low;
            re = guess(mid);
        }
        return mid;
    }
};
