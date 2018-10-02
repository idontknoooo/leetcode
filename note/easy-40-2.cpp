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
	3. Handle 4 = 2 + 2 // multiple same number
// }
// 171. Excel Sheet Column Number
// {
		// a. Horner's Algorithm
// }
// 189. Rotate Array
// {
	1. reverse(vec.begin(), vec.end());
	// 2. Also, think about extreme case, like over size
// }
// 203. Remove Linked List Elements
// {
	// 1. Main difference: The beginning vs in the middle. Not a difficult one.
// }
// 217. Contains Duplicate
// {
	// 1. Sort and iterate
// }
// 219. Contains Duplicate III
// {
	  // use hashset to keep distance k, so that there won't be any repeat
// }
// 225. Implement Stack Using Queues
// {
	// 1. Queue pop() doesn't return anything
	// 2. Queue top() and empty() is same as Stack
	// 3. Queue push() to the end, while stack push() to the top
// }
// 226. Invert Binary Tree
// {
	// 1. Always check empty tree
	// 2. Recursively: sway left & right by recursive to the leaf
// }
// 232. Implement Queue Using Stacks
//{
  //  1. stack top == queue front
  //  2. Queue always add to back
//}
// 234. Palindrome Linked List
// {
  //  1. Double pointer: reverse list from middle to end, and compare to begining to mid
// }
// 237. Delete Node in a linked list
// {
  //   1. kinda stupid, but just skip this current node
// }
// 238. Move Zeros
// {
	// 1. Double pointer to move non-zero number to front and make all rest position Zero
// }
// 290. Word Pattern
// {
	// 1. Use stringstream & unordered_map & unordered_set 
// }
// 303. Range Sum Query - Immutable
// {
	// 1. Use continous sum: 
	// e.g.
	// 	arr = [2, 4, -5, 6, 1, 4]
	// 	to
	// 	sum = [2, 2+4, 2+4+(-5), 2+4+(-5)+6, ....]
	// 	equals to
	// 	sum = [2, 6, 1, 7, 8, 12]
	// 	then:
	// 	sum of [0, 4] is: 8
	// 	sum of [0, 1] is: 6
	// 	sum of [2, 4] is: [0,4] - [0-1] = 8 - 6 = 2
	// 	sum of [i, j] = [0, j] - [0, i-1]
// }
// 326. Power of three 
// {
	// 1. Normal method: loop divide 3
	// 2. Use mathematic method: check "326_Power_of_Three.cpp"
// }
// 342. Power of Four
// {
	// 1. Normal Method: loop divide 4
	// 2. Bitwise operation
// }
// 344. Reverse string
// {
	// 1. Use extra space by initialize a variable (faster)
	// 2. No extra space by swap corresponding position (save space but slower)
// }
// 345. Reverse Vowels of a string
// {
	// 1. Several functions:
		tolower('U') // Convert U to u
		string s;
		// return the position when found character in that string. Start from position j
		s.find_first_of("aeiouAEIOU", j); 
	// 2. Main method: Double pointer. A pointer from front, the other pointer from end. Use swap when found both vowels
	// 3. In this question, try avoid use tolower() conversion since find in 10 chars will faster than type conversion
	// 4. 
// }
// 349. Intersection of Two Arrays
// {
	// 1. Declare a unordered_set based on a vector 
	vector<int> num1;
	unordered_set<int> m(num1.begin(), num1.end());
	m.count(a) // count the number of 'a' in set m
	m.erase(a) // remove a from m
// }
// 350. Intersection of Two Arrays II 
// {
	// 1. Slow and space wasting method: use unordered_map with vector
	// 2. Same logic, use an unordered_multiset will be faster
	// 3. use <algorithm>, first sort 2 arrays
	set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr1.begin(), arr1.end());
	set_intersection(start, end, start1, end1, store, compare);
// }
// 367. Vaild Perfect Square
// {
	// 1. Bisection method 
	// 2. Newton method 
	// 3. Q_rsqrt method // https://en.wikipedia.org/wiki/Fast_inverse_square_root
// }
// 371. Sum of Two Integers
// {
// 	1. https://leetcode.com/problems/sum-of-two-integers/discuss/84278
// 	2. Bitwise operation 
// }
// 374. Guess Number Higher or Lower
// {
// 	Guess number using bisection method
// }
