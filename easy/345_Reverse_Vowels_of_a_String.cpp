class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        char c1 = ' ', c2 = ' ';
        for(int i = 0, j = s.length()-1; i < j; )
        {
            if(vowels.find(tolower(s[i]))!=vowels.end())
                c1 = s[i];
            else
                ++i;
            if(vowels.find(tolower(s[j]))!=vowels.end())
                c2 = s[j];
            else
                --j;
            if(c1 != ' ' && c2 != ' ')
            {
                s[i] = c2;
                s[j] = c1;
                c1 = ' ';
                c2 = ' ';
                ++i;
                --j;
            }
        }
        return s;
    }
};
// class Solution {
// public:
//     string reverseVowels(string s) {
//         int left = 0, right= s.size() - 1;
//         while (left < right) {
//             if (isVowel(s[left]) && isVowel(s[right])) {
//                 swap(s[left++], s[right--]);
//             } else if (isVowel(s[left])) {
//                 --right;
//             } else {
//                 ++left;
//             }
//         }
//         return s;
//     }
//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
//     }
// };
// class Solution {
// public:
//     string reverseVowels(string s) {
//         int i = 0, j = s.size() - 1;
//         while (i < j) {
//             i = s.find_first_of("aeiouAEIOU", i);
//             j = s.find_last_of("aeiouAEIOU", j);
//             if (i < j) {
//                 swap(s[i++], s[j--]);
//             }
//         }
//         return s;
//     }
// };

// class Solution {
// public:
//     string reverseVowels(string s) {
//         int dict[256] = {0};
//         dict['a'] = 1, dict['A'] = 1;
//         dict['e'] = 1, dict['E'] = 1;
//         dict['i'] = 1, dict['I'] = 1;
//         dict['o'] = 1, dict['O'] = 1;
//         dict['u'] = 1, dict['U'] = 1;
//         int start = 0, end = (int)s.size() - 1;
//         while(start < end){
//             while(start < end && dict[s[start]] == 0) start++;
//             while(start < end && dict[s[end]] == 0) end--;
//             swap(s[start],s[end]);
//             start++;end--;
//         }
//         return s;
//     }
// };