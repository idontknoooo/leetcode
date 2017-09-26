class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }
    
        return true;
    }
};

// Pretty similar to previous one
// For vs While, while vs while(if)
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0, end=s.length()-1;
        while(start<end) {
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else {
                if (tolower(s[start++])!=tolower(s[end--])) return false;
            }
        }
        return true;
    }
};
