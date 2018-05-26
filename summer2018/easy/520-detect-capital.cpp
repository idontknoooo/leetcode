class Solution {
public:
    bool detectCapitalUse(string word) {
        bool result = false;
        int wordSize = word.length();
        if(wordSize == 1) return true;
        else{
            if(word[0] <= 90){
                if(word[1] >= 97){
                    for(int i = 2; i < wordSize; i++){
                        if(word[i] < 97) return result;
                    }
                    result = true;
                    return result;
                }
                else{
                    for(int i = 2; i < wordSize; i++){
                        if(word[i] >= 97) return result;
                    }
                    result = true;
                    return result;
                }
            }
            else if(word[0] >= 97){
                for(int i = 1; i < wordSize; i++){
                    if(word[i] < 97){
                        return result;
                    }
                }
                result = true;
                return result;
            }
        }
    }
};

// Better, count length of string
class Solution {
public:
   bool detectCapitalUse(string word) {
     int upper = 0;
     for (auto& i : word) if (i < 97) ++upper;
     return upper == 0 || (word[0] < 97 && upper == 1) || upper == word.size();
  }
};
