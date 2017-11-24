string countAndSay(int n) {
	string ret = "1";
	// For n strings
	while(--n) {
		string next;
		size_t i = 0;
		// For each string
		while(i < ret.length()) {
			char ch = ret[i]; // current char
			int c = 0;
			// Print next string
			while(i < ret.length() && ret[i] == ch) {
				i++; // Count iteration
				c++; // Count occurance of char
			}
			next.push_back(c + '0'); // push back # of char
			next.push_back(ch); // push back char
		}
		swap(ret, next);
	}
	return ret;
}
// A 0ms solution
class Solution {
public:
  
    string countAndSay(int n) 
    {
    	string s,temp;
		int i,j,k,count=1;
		s = "1";
		for(i=1;i<n;i++)
		{
			count = 1;
			k = s.length();
			temp = "";
			for(j=0;j<k;j++)
			{
				if(s[j]==s[j+1])
					count ++;
				else if(s[j]!=s[j+1])
				{
					temp += count + '0';
					temp += s[j];	
					count = 1;
				}
			}
			s=temp;
		}
	return s;
    }
};