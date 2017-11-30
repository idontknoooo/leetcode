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
// 1. Two Sum
// {
		#include <unordered_map> // include <unordered_map>
		unordered_map<int, int> map // hashmap in C++
		map.find(key) // map.find() find key, not value
		unordered_map<int, int>::iterator p = map.begin(); // iterator
		p->second; // value for key
		p->first; // key
		map[key] = value; // store pair in map
// }
// 7. Reverse Integer
// {
	// Use nemeric method instead of string method
	INT_MIN //: Minimum value for an object of type int (-2^15+1 or less)
	INT_MAX //: Maxmium value for an object of type int (2^15-1 or more)
	to_string(int) // Convert int to string
	stoi(string) // covert string to int
	stol(string) // convert string to long
	stoll(string) // convert string to long long
// }
// 13. Roman to Integer
// {
		// 1. https://en.wikipedia.org/wiki/Roman_numerals
		// 2. Think in both string and integer ways
		// 3. 重复数次：一个罗马数字重复几次，就表示这个数的几倍。
		// 4. 右加左减：
		// 		在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
		// 		在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
		// 5. 同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
		// 6. Declare Map with initialization
        unordered_map<char, int> mp {
	 	{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
		};
		// 7. Last element of string s
		s.back(); // C++11
		s.back() = '!'; // Since back() return reference, you can assign new value to it
		s.front(); // first element of string, C++11
		// 8. Access String element
		s[i]; // pass reference
		s.at(i); // same as above
// }
// 14. Longest Common Prefix
// {
	// 1. Understand what is common prefix: same starting chars among different strings	
	// 2. Bucket Principal: The shortest decides everything. 
	// 		In this case, common prefix between first 2 string is crucial, 
	//		since that is the first common prefix
	// 3.  Simulate the process by using trivial example with pen
// }
// 20. Valid Parentheses
// {
	// 1. Stack methods:
		stack<int> s;
		s.size();
		s.top();
		s.pop(); // does NOT return anything, so usually combine with top() when use
		s.push();
		s.empty();
	// 2. String functions
		string s = "hello";
		string s1 = "world";
		s.compare(s1); // return 0 when two strings are same, <0 s is shorter or lower than s1
		s.find('c'); // search a char in string and return iterator, string::npos is not found
		s.find('string'); // search a string in string and return iterator
		std::size_t found = s.find('c');
		if(found!=std::string::npos)
			cout << "found at " << found << endl;
		std::size_t // Unsigned integral type. Alias of one of the fundamental unsigned integer types.
		// position does not match ANY char in string
		s.find_first_not_of(' '); // Searches the string for the first character that does not match any of the characters specified in its arguments.
		// ANY of char in search string
		s.find_first_of(''); // Searches the string for the first character that matches any of the characters specified in its arguments.
		s.find_last_not_of('dc'); // last one
		s.find_last_of('sc'); // last one
		s.insert(s.begin(),'something'); // insert string(char) or char at position(or iterator)
		s.insert(10, 3, '-'); // insert 3 '-' at position 10
	// 3. Ascii to compare neighbours
		if('{'+1 != (int)c) // check whether c == '}', which is match to '{'
// }
// 21. Merge Two Sorted Lists
// {
	// 1. Note Lists are SORTED!
	// 2. Use 2 pointers on lists and move them accordingly
	// 3. First Node can be discard, since it does NOT have a value
	// 4. Empty list doesn't matter, since the end of list is NULL
	// 5. Declare listnode
			// Definition for singly-linked list.
			struct ListNode {
			    int val;
			    ListNode *next;
			    ListNode(int x) : val(x), next(NULL) {}
			};
			ListNode* node = new ListNode(INT_MIN);
// }
// 26. Remove Duplicates From Sorted Array
// {
	// 1. Update vector using double pointer
	// 2. std functions:
	// get unique value placed from beginning of vector
		vector<int>::iterator it = std::unique(vec.begin(), vec.end()); 
		vec.erase(it, vec.end());	// erase from iterator a to iterator b
// }
// 27. Remove Element
// {
	// 1. Double pointer	
// }
// 28. Implement strStr()
// {
	// 1. Check the match size and see whether it is same as 'needle', O(n^2)
// }
// 35. Search Insert Position
// { 
	// a. Binary Search: Need to remember: https://en.wikipedia.org/wiki/Binary_search_algorithm
	// b. Binary search will low(mid), thus use 'left' as return value
	// 		When a number x is <= nums[right], always right=mid-1, since it doesn't matter whether it is less than or equal, x will always be before 'right'
	// 		However, when a number x >= nums[left], it matters whether it is > or ==, since if it's > nums[left], x should be place after 'left'; if x == nums[right], x should be place before 'left'.
// }
// 38. Count And Say
// {
	// a. A 3 nested loop question, not hard but need thoroughly thinking, better to write down
	// b. convert int to char, int+'0'
		int num = 9;
		char c = num+'0'; // use ascii;
		int num1 = 99;
		string s = to_string(num1); // use to_string
	// c. void swap(T a, T b) to swap return & tmp(next)
	// d. Swap is everywhere: if a variable is replaced by another in each iteration, then add a tmp can solve it.
	// e. the last char of string is '\0'. Meaning the end of string.
// }
// 53. Maximum Array
// {
	// a. If current_sum > 0, then it will be useful for next number
	// 	when current_sum > 0, if next < 0, then max will be the same, current_sum += 'next'
	// 						  if next > 0, then max will be current_sum + 'next'
	// 	when current_sum < 0, if next < 0, then max will be the same, clear current_sum value to 0
	// 						  if next > 0, then max will be just 'next', since currrent_sum is useless
	// b. have a variable calculate 'current_non_negative_sum' and a variable store 'max'
// }
// 58. Length Of Last Word
// {
	// a. Find condition:
	// 	Start point: first point from right where != ' ' 
	// 	End point: after start point, first point where == ' '
	// b. Increment a length variable, not counting the iteration of moving iterator 'i'
// }
// 66. Plus One
// {
	// a. Analyze how numbers will change
		// only way to carry is 9+1 (10%10==1)
		// Only time to add element into vector is adding 1 at beginning (vec.insert(vec.begin(),1))
		vec.insert(vec.begin(), 1);
	// b. Handle carry and adding element
// }
// 67. Add Binary
// {
		// 1. To simplify the if...else statement, think about the output of condition, e.g.
		carry =  (tmp/2>0)? 1 : 0;
		// Can be replaced by
		carry = tmp/2;
		// 2. Everytime when there is arithmatics on string or vectors, think about division(/) and mod(%),
			// because they tell you when to carry(/) and what to save at this digit(%);
		// 3. To save lines, when pointer is not being used in further but need Increment,
			// do it by post increment when using it, e.g.
		tmp = char(a[pb]-'0');
		pb--;
		// Instead above, use this:
		tmp = char(a[pb--]-'0');
		// 4. When doing check for multiple part at the same time, consider to if check for each part separately
		if(pa >= 0 && pb >= 0) ...
		else if(pa >= 0)
		else if(pb >= 0)
		// instead above do this:
		if(pa>=0)  
		if(pb>=0)	
		// Doing these, save lots of lines to if statement content
	// a. Find carry condition
	// b. char calculation: 
		'1' - '0' == 1
		1 + '0' == ascii(1) == 49
		char(1) != char(1+'0') == 1 == char(49)
		int('0') == 48 != 0 = '0'-'0'
// }
// 69. Sqrt(x)
// {
	// a. Newton's Iterative Method need to remember 近似求解方程的方法
	// Xn = X_n-1 - f(X_n-1)/f'(X_n-1). X_n will always be close to real solution than X_n-1
	// ans = ans - (ans^2-x)/(2*ans);
	int mySqrt(int x) {
        double ans    = x;
        double delta  = 0.0001;
        while (abs(pow(ans, 2) - x) > delta) {
		// ans = ans - (ans^2-x)/(2*ans);
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
	// b. x0 = x (initial guess)
	// 	Xn = X_n-1 - f(X_n-1)/f'(X_n-1)
	// 	   = X_n-1 - (X_n-1^2-X)/(2*X_n-1)
	// 	   = X_0 - f(X_0)/f'(X_0) - f(X_1)/f'(X_1) ..... 
	// c. f(a) = a^2 - x
	//    f'(a) = 2a
// }

// 70. Climbing Stairs
// {
	// a. New step can be reach be climb 1 step from previous step (1 way), or 2 steps from pre-previous stop (1 way). 
	// Also, the path to previous and pre-previous are totally different, because they have different numbers of steps.
	// Thus, by adding two previous ways, you got new step.
	// b. Same as fibonacci series
	// Iteratively
	int fibonacci(int n){
		int a = 0, b = 1;
		int re = 0;
		if(n<=1) return a;
		if(n==2) return b;
		while(n-- > 2){
			re = a + b;
			a = b;
			b = re;
		}	
		return re;
	}
	// Recursive
	int fibonacci1(int n){
		int a = 0, b = 1;
		if(n<=1) return 0;
		else if(n==2) return 1;
		else
			return fibonacci(n-1) + fibonacci(n-2);
	}
// }
// 83. Remove Duplicates From Sorted List
// {
	// Easy, remember this is a sorted list and only keep the first repeat number and unlink the rest.
	// 1. Single pointer
	// 2. Always check last element when it can be NULL 
	// 3. Check either one-by-one or all in once
	// all-in-once is faster
// }
// 88. Merge Sorted Array
// {
	// Since they are array, think how fixed size container works
	// They always initialize enought space before use
	// a. From the most right (not left)
	// b. Handle nums2 mainly, since nums1 will stay in itself	
// }
// 100. Same Tree
// {
	// a. Check whether a pointer is NULL:
	// 	if(p)
	// 		cout << "Not NULL" << endl;
	// 	if(!p)
	// 		cout << "Is NULL" << endl;
	// b. Process:
	// {
	// 	Think about process
	// 	Use character of Tree to 'devide branch' & 'recursion'
	// }	
// }
// 101. Sysmmetric Tree
// {
	// a. Think base case and recursion
	// b. Create a helper function
	// c. One trick: Use same root, but flip tree to compare original with fliped
// }
// 104. Maximum Depth Of Binary Tree(Height of binary tree)
// {
	// Always think about the base case
	// a. DFS method comes to mind, recursion
	// b. BFS is also a solution, iteratively
// }
// 107. Binary Tree Level Order Traversal II
// {
	// a. BFS solution, like Question_104. Need a Queue to pop parent layer
	// b. to reverse
	std::reverse(vec.begin(), vec.end()) 
	For Tree Questions
	{
		consider following questions:
		1. Base case: 0 node, 1 node, (2 nodes)
		2. Handle leaves (NULL)
		3. Always think about Tree structure (root, root->left, root->right), this is how things are recursive;
	}
// }
// 108. Convert Sorted Array to Binary Search Tree
// {
	// a. BST left_child <= curr <= right_child, thus, root should be in middle of vector (left < middle < right, since vector is sorted) 
	// b. Create new vector using interator:
		vector<int> leftints(vec.begin(), num.begin()+middle);
	// c. Find all root, then assign it left & right child
	// d. Do this as an iterative process
// }
// 110. Balanced Binary Tree
// {
	// a. Need to understand the problem
	// 	Each node's depth of two subtrees never different by more than 1.
	// b. [1,2,3,4,null,null,9,8,null,null,10] one test case
	// c. Only make sure it is balanced from bottom, it can be balanced up until top
	// d. If only check 2 branch of root, it will miss the difference in each subtree. Check tree in 'b'
	// e. The difference is the criteria for balance 
// }
// 111. Minimum Depth of Binary Tree
// {
	// a. Very similar to "Max Depth BT", use recursion and modify a few feature
	// b. [1,2] has min depth 2, not 1; Min depth: root to closest leaf; not root to root.
	// Root cannot be leaf in this question, that when min kicks in
// }
// 112. Path Sum
// {
	// a. Find the pattern: each recursion take (sum-curr->val) as search sum
	// b. handle base case
	// c. Special case, unless root is the only node, root cannot be only value of branch
	// 	[1,2] find 1, return false, because only branch is 1->2, which sum to 3 not 1
	// d. Final situation: when 
	(sum-curr->val == 0 && !root->left && !root->right)
// }
// 118. Pascals Triangle
// {
	// a. If size of vector has a pattern, declare its size before add value. 'push_back' take time	 
	// b. Find pattern
	// c. When possible use vector as an array
	// e.g. Declare the size of vector 
	vec.resize(10); // size == 10
	// initialize vector size
	vector<vector<int> > vec(10); // vector of 10 vectors
	// Array style assignment, instead of use 'push_back()', use as follow
	r[i][j] = r[i-1][j-1] + r[i-1][j];
// }
// 119. Pascal's Triangle II
// {
	// a. NICE to declare size in advance
	// b. Base case:	
	// 	level0 is [1]
	// 	level1 is [1,1]
	// c. Nicer solution is solve from end, since size increases each iteration
// }
// 121. Best Time To Buy and Sell Stock
// {
	// a. When there is a example, try to go through it until the end. This helps understand question.
// }
// 122. Best Time To Buy and Sell Stock II
// {
	// a. Mathematics: 结合律 
	// [1,2,6]: max = 6-1 = 5
	// max = (2-1)+(6-2) = 6-2+2-1 = 5
	// 	Suppose a <= b <= c <= d, Max difference is d-a = (b-a)+(c-b)+(d-c)
	// 	Since for this question, you can't engage in multiple transaction.
	// 	Thus, the best we can do is: (b-a) + (d-c) <= d-a
	// 	Thus, as long as there is an increase sequence, (d-a) is the max value
// }
// 125. Valid Palindrome
// {
	#include <cctype>
	isalnum() //: check whether ialphanumeric (A-Za-z0-9)
	isalpha() //: Check whether letter (A-Za-z)
	isdigit() //: check whether digit (0-9)
	
// 	d. Start from 2 sides, faster
// }
// 136. Single Number
// {
	a. A XOR A == 0;
		0 ^ A == A, where A!=0	
	b. Use 0^A, iterate entire vector, return A
	c. accumulate(iter.begin(), iter.end(), init_val, binary_operation)
		#include <functional> // C++11
		#include <numeric> // accumulate
		accumulate(vec.begin(), vec.end(), 0, bit_xor<int>());
	d. Hashmap method
	e. Mathematics method
// }
141. Linked List Cycle
{
	a. Faster-slower runner method, faster will meet slower eventually
	b. unordered_set methods 
}
155. Min Stack
{
	a. Stack is faster than vector
	b. To make constant min value return, spend time on storing val when do other operations
}
157. Read N Characters Given Read4
{
	a. For this question, read4() can be only used in one clause for read, otherwise, it will messed up
	b. when count iteration, use minus or division, two choice pick the best
		15 4
		15-4 leave 3, i-=4
		15/4 mod 3, need variables for dividend & mod
}
160. Intersection Of Two Linked Lists
{
	a. If no intersection, both node move to null
	b. To make two lists iterate in same pace, just need to find their length difference
	c. Then the longer one start from (length - diff) so they will in same pace
}
167. Two Sum II - Input Array Is Sorted
{
	a. This question assume there must be a solution (two numbers)
	b. Start from 2 end, 
		if sum > target, right end move left
		if sum <= target, left end move right
		if sum == target, return vector<int> ({left, right})
}
168. Excel Sheet Column Title
{
	a. Handle a(1) & z(26) special case
	b. Use n/26 to generate each leter
	c. Also, see a recursive method
	d. Number to Letter: (--num%26) + 'A'
		1 -> A
		26-> Z
		[1-26] % 26 = [1-25,0]
		[0-25] % 26 = [0, 25]
}
