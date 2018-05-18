class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int digit = 0; 
        int i = 0, j = 0;
        for(i = 0, j = 0; i < abbr.length() && j < word.length(); ){
            if(isalpha(abbr[i])){
                if(abbr[i++] != word[j++]) return false;
            } else if(isdigit(abbr[i])) {
                if(abbr[i]=='0') return false;
                digit = abbr[i]-'0';
                int tmp = i+1;    
                while(isdigit(abbr[tmp]) && tmp < abbr.length()){
                    digit = digit*10 + abbr[tmp] - '0';
                    tmp++;
                }
                i += tmp-i;
                j += digit;
            }
        }
        return digit<=word.length() && i == abbr.length() && j == word.length();
    }
};

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        
        while(i<word.size() && j < abbr.size()) {
            if (isLetter(abbr[j])) {
                if (abbr[j] == word[i]) {
                    i++;j++;
                } else {
                    return false;
                } 
            } else {
                int n = 0;
                if ( abbr[j] == '0')
                    return false;
                while(j < abbr.size()&& is_digit(abbr[j])) {
                    n = n*10 + abbr[j++]-'0';
                }
                i = i+n;
                if (i>word.size())
                    return false;
            }
        }
        return i==word.size() && j==abbr.size();
    }
    
    bool is_digit(char a) {
        return (a>='0' && a<='9');
    }
    
    bool isLetter(char b) {
        return ((b>='a' && b<='z') || (b>='A' && b<='Z'));
    }
};
