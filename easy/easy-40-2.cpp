// General
// {
//	 	1. Code to get faster running time in Leetcode
//	 	{
			// x is input value
			static int x=[](){
				// toggle off cout & cin, instead, use printf & scanf
			    std::ios::sync_with_stdio(false);
			    // untie cin & cout
			    cin.tie(NULL);
			    return 0;
			}(); // add () because it create lambda function and CALLED it.
//	 	}
//		2. Horner's Algorithm: y = A0 + A1*x + A2*x^2 + ... + An*x^n
//	 	{
			// Naive method O(n^2) since x^n -> O(n)
			vector<int> a = {1,2,3,4,5};
			int y = 0;
			int x = 2;
			for(int i = 0; i < 5; ++i){
				y += a[i]*pow(x,i);
			}
			cout << y << endl;
			// Horner's algorithm: O(n)
			y = a[4]*x+a[3];
			for(int i = 3; i > 0; --i){
				y = y*x+a[i-1];
			}
			cout << y << endl;
			return 0;	
//	 	}
		// 3. Moving Average
		// {
			vector<int> vec = {32,41,41,35,43,53,61,35,61};
			int n_day = 3;
			vector<int> ma;
			double pre = (vec[0] + vec[1] + vec[2])/3.0;
			ma.push_back(pre);
			int first = vec[0];
			int last = vec[3];
			for(int i = 1; i < vec.size()-n_day; ++i)
			{
				// Use this add & minus trick to calculate new moving average instead of recalc
				double cur = (pre*n_day - first + last)/(n_day*1.0);
				ma.push_back(cur);
				first = vec[i];
				last = vec[i+3];
				pre = cur;
			}
		// }
// }
// Questions
// 169. Majority Element
// {
		a. find(nums.begin(), nums.end(), to_be_found); // find a variable
		b. count(nums.begin(), nums.end(), to_be_counted); // count a variable
		c. Moore Voting Algorithm: 
			// The Boyer–Moore majority vote algorithm is an algorithm for 
			// finding the majority of a sequence of elements using linear time 
			// and constant space
// }
// 170. Two Sum III - Data Structure Design
// {
	1. unordered_multiset<int> nums;	// Allow repeat
	2. x << y  // equals x * (2^y)
	// 	e.g. 2 << 1: 2*2 = 4
	3. 
// }
// 171. Excel Sheet Column Number
// {
		// a. Horner's Algorithm
// }