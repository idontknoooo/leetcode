// My solution 18ms
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = char('z' + 1);
        char min_c = ans;
        for(char c : letters){
            min_c = min(min_c, c);
            if(c > target && c < ans) ans = c;
        }
        return ans==char('z'+1)? min_c : ans;
    }
};

// 15ms
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[0] > target || letters.back() <= target) return letters[0];
        
        int low = 0, high = letters.size()-1;
        char res;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(letters[mid] > target && (mid == 0 || letters[mid-1] <= target)) {
                res = letters[mid];
                break;
            }
            else if(letters[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return res;
    }
};
