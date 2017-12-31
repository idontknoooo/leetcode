class Solution {
public:
	// Will use extra space
    string reverseString(string s) {
        // std::string tmp = "";
        // for(int i = s.length()-1; i >= 0; --i)
        // {
        //     tmp += s[i];
        // }
        // return tmp; 
        return string(s.rbegin(), s.rend());
    }
};


// Use swap(): no extract space used
class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};
// Create my own swap
// swap(s[i++], s[j--])
void swap(char& val1, char& val2)
{
	char tmp = val1;
	val1 = val2;
	val2 = tmp;
}
// Use pointer 
// Function call swap(&s[i++], &s[j--])
void swap(char* pos1, char* pos2)
{
    char tmp = *pos1;
    *pos1 = *pos2;
    *pos2 = tmp;
}