// My solution 29ms beat 9%
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Handle special case
        if(flowerbed==vector<int> {0} && n <= 1) return true;
        if(flowerbed==vector<int> {1} && n > 0) return false;
        int lead = 0, i = 0, j = flowerbed.size()-1;
        // Handle leading 0
        for(; i < flowerbed.size(); ++i){
            if(!flowerbed[i]){
                ++lead;
            } else break;
        }
        if(i != j+1)
            n -= lead / 2;
        else n -= (lead+1) / 2;
        lead = 0;
        // Handle tailing 0
        for(; j > i; --j){
            if(!flowerbed[j]){
                ++lead;
            } else break;
        }
        if(i != j+1)
            n -= lead / 2;
        else n -= (lead+1) / 2;
        lead = 0;
        // Handle middle zero
        int a = i, b = i + 1;
        for(; b <= j; ){
            if(flowerbed[b]){
                n -= (lead-1) / 2; 
                lead = 0;
                a = b++;
            } else {
                ++lead;
                b++;
            }
        }
        return n <= 0;
    }
};


// 18ms solution, beat 99%
// 0,0,0 -> 1 flower, append zero to lead & tailing zero
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int len = flowerbed.size();
      for (int i = 0; i < len; i++) {
        if (flowerbed[i] == 0) {
          int pre = (i == 0) ? 0 : flowerbed[i - 1];
          int next_ = (i == (len - 1)) ? 0 : flowerbed[i + 1];
          if (pre + next_ == 0) {
            n--;
            flowerbed[i] = 1;
          }
        }
      }
      return (n <= 0);
    }
};
