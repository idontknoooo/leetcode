#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) { return 0; }
        unordered_map<char, int> mp {
	 	{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
		};
        int sum = mp[s.back()];
		// size()-2 is to i+1 inside for loop
        for (int i = s.size() - 2; i >= 0; --i) {
			// Roman numerial rule
			// Right symbol cannot > 3
			// Left less symbol can only be 1
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
    }
};
int main()
{

}
