#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		// If less than 0 or ending with a 0
		if(x<0|| (x!=0 && x%10==0)) return false;
		int sum=0;
		while(x>sum) // if x <= sum, then they half is done
		{
			sum = sum*10+x%10;
			x = x/10;
		}
		//cout << x << "---" << sum << endl;
		return (x==sum)||(x==sum/10); // Ignore middle digit for odd number by dividing by 10
	}
};
int main()
{
	Solution s;
	s.isPalindrome(13531);
}
