class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // int i = 0, j = 0;
        // while (i < word.size() && j < abbr.size()) {
        //     if (isdigit(abbr[j])) {
        //         if (abbr[j] == '0') return false;
        //         int val = 0;
        //         while (j < abbr.size() && isdigit(abbr[j])) 
        //             val = val * 10 + abbr[j++] - '0';
        //         i += val;
        //     }
        //     else if (word[i++] != abbr[j++]) return false;
        // }
        // return i == word.size() && j == abbr.size();
        int i = word.size()-1;
        int j = abbr.size()-1;
        //int prevnum = 0;
        //bool prevnum = false;
        //vector<int> nums;
        int digcount = 0;
        int totdig = 0;
        while(j>=0) {
            if(isalpha(abbr[j]) && totdig==0 && digcount>0) {
                return false;
            }
            if(isalpha(abbr[j]) && totdig>0) {
                i-=totdig;
                //cout << "totdig:" << totdig << endl;
                totdig = 0;
                digcount = 0;
            }
            if(i>=0 && (abbr[j] == word[i])) {
                j--;
                i--;
            } else if(isdigit(abbr[j])) {
                if(totdig>0&&abbr[j]=='0') {
                    return false;
                } 
                totdig += int(abbr[j]-'0') * pow(10,digcount);
                //cout << "*totdig:" << totdig <<endl;
                digcount++;
                j--;
                //i--;
            } else {
                return false;
            }
        }
        //cout << "i:" << i << endl;
        //cout << "digcount:" << digcount << endl;
        
        if((i+1) == totdig) {
            return true;
        } else if(i>=0) {
            return false;
        } else if(i<0 && totdig>0) {
            return false;
        }
        return true;
    }
};
