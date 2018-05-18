class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};


class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> um = {
            {'a',1}, {'e',1}, {'i',1}, {'o',1}, {'u',1},
            {'A',1}, {'E',1}, {'I',1}, {'O',1}, {'U',1}
        };
        int l = 0, r = s.length()-1;
        while(l < r){
           if(um[s[l]] && um[s[r]]) {
               char tmp = s[r];
               s[r] = s[l];
               s[l] = tmp;
               --r, ++l;
           } else if(um[s[l]]){
               --r;
           } else if(um[s[r]]) {
               ++l;
           } else {
               --r, ++l;
           }
        }
        return s;
    }
};
