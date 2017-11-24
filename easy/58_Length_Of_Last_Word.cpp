class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        // Handle empty tail first
        while (tail >= 0 && s[tail] == ' ') tail--;
        // Then, handle non-empty tail
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};

// Just another way to think
int lengthOfLastWord(string s) {

	if(!s.length()) return 0;
	int count = 0, i = s.length()-1;
	while(i >= 0){
		if(s[i]!=' '){
			count += 1;
		else if(count && s[i] == ' '){
			return count;
		// if 'count' hasn't start and still empty, then pass
		--i;
	}
	return count;
}