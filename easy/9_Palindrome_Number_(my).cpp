#include <iostream>
using namespace std;
int main()
{
	class Solution {
	public:
		int reverse(int x) {
			long long res = 0;
			while(x) {
				res = res*10 + x%10;
				x /= 10;
			}
			return res;
		}
		bool isPalindrome(int x) {
			return (x<0)? false : (x==reverse(x))? true : false;   
		}
	};
}
