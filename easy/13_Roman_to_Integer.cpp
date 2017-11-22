#include <iostream>
#include <unordered_map>
using namespace std;
// Add From back
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

// Add from front, initialize as last element but it still add from front 
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> match;
        match['I']=1;
        match['V']=5;
        match['X']=10;
        match['L']=50;
        match['C']=100;
        match['D']=500;
        match['M']=1000;
        int result=match[s[s.size()-1]];
        for(int i=0;i<s.size()-1;i++){
            if(match[s[i]] < match[s[i+1]]){
                result -= match[s[i]];
            } else{
                result += match[s[i]];
            }
        }
        return result;
    }
};
int main()
{

}
