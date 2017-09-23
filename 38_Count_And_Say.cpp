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
