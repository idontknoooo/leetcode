/* Array */
// If knowing size and not changing, then use array with memset
int arr[n];
memset(n, 0, sizeof(A));


/* if statement */
// 1. 101-symmetric-tree: if simplify
func(){
  if(a)
    return func();
  else if(b)
    return true;
  else 
    return false;
}
// Above can be rewrited as below, since func() return true/false from 'b'
func(){
  return a && func() || b;
}

/* Vector */
return {1,2,3} // vector<int> literal without declare 
return {}      // Empty literal
vector<int> vec;
vec['X'] = 1;  // Use character as index
// Some questions, you can intialize the size first then add value and add from end to begin: 118-pascals-triangle
vec.back() == vec[vec.size()-1]; // Use vec.back
k %= vec.size() // rotate number cannot more than length of vector
vec.size()-1    // if vec is empty, result is Not -1, it will be 18446744073709551615, since vec.end()==-1


/* Stack */
// Time series min_stack method: 155: Min stack
stack<int> s;
s.push(x);
s.pop();   // Pop top
s.top();   // There is no bottom() method
// Pop & push in single loop doesn't work on stack


/* Queue */ 
queue<int> q;
q.front();
q.back();
q.pop();   // Pop out front
q.push(x); // Push to back
// Pop & push in single loop q.size() times will keep queue as the same queue


/* Unordered Map */
unordered_map<int, int> um = {
  {1,2}, {2,0}
} // Use ',' to initialize not ':'
if(um.find(kk) != um.end()) // Found (exist in map)
um[kk] // Return 0 if doesn't exist, BUT if the value is 0, then there is a misleading singal
if(um[kk])                  // Exist, but it will missing when value is 0
if(!um[kk])                 // NOT "Not Found", since it might because the value is 0
// For sorted vector, you no need unordered map
// When knowing the total size of mapping, use vector(array) instead of unordered_map since it might be faster: 242-valid-anagram




/* string */
string ss = "([{";
if(ss.find('(') != string::npos) // Found (exist in string) 
if(ss.find('(') != -1)           // Same as above 
string::npos // means "until the end of the string". This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type. 
to_string(8); // Convert int, double .. to string


/* Character */
int a = '5' - '0' // Same as 5-0. Char arithematics
'A' + 1           // return 66, since 'A' is 65
(char)('A' + 1)   // return B , type casting


/* Tree */
TreeNode *p, *q;
p==q?             // If last node, you can compare this way
p->val==q->val?   // If not last node, only compare value
Treenode* func()  // When create new TreeNode() need to return cannot be void. 108. Convert sorted vector to binary search tree
// Binary search tree index: 108
//  begin = 0, end = vector.size()-1
//  mid = (end+begin)/2
//  begin, mid-1 // left subtree
//  mid+1, end   // right subtree
// Invert tree: Invert from bottom level. Always think base case, that's intuitive for tree.
// Binary search tree: least common ancestor of a & b always the first node in between of [a, b] traverse from head, moving one extra to left will decrease upper bound which will lose max(a,b) as child, moving one extra to right will increase the lower bound which will lose min(a,b) as child: 235-lowest-common-ancestor


/* Linked List */
// Double pointer: slow vs fast to detect whether there is a cycle
// Reverse list: Consider the node before head node as NULL
// End to top: Using recursive can achieve operating from last node then go back until to head node (just like tree) 234 Palindrom linked list


/* Edge Case */
// 1. int vs long vs long long
// 2. Negative number
// 3. Zero
// 4. Empty container


/* Bitwise Operation */
int a = 4;
a>>1          // Equal to a/2 = 2; Also, remove the most right bit
a<<1          // Equal to a*2 = 8; Also, remove most left bit and add 0 from most right bit
cout << a>>1; // Illegal (conflict after cout)
int b = a>>1; // Legal. b will equal to 2
int tmp = a^a           // return 0, since a==a
int tmp = 0^a           // return a. 1^0->1, 0^0->0
n &= n-1      // Change 1 bit at a time, make bit with value 1 to 0 one by one. 1 will become to 0 by &, and no new '1' will occur
n & 1         // Only keep most right bit and ingore all other bit
if(a==b) 
if(!(a^b))    // Faster than above when a and b are integers


/* Notice */
// 1. Reference vs Pointer vs Value


/* Standard Library */
INT_MAX // Max of int in C++, <climits>
INT_MIN // Min of int in C++
size_t  // Could be any unsigned type: unsigned char, unsigned int, unsigned long etc.
return; // Can be used in void function, this doesn't return anything
NULL    // not null;
nullptr // same as above
isalpha() // Check if it's letter
isdigit() // Check if it's number 
isalnum() // Check if it's letter or number
sort(vec.begin(), vec.end());// Sort vector
static bool myComp(const Interval& it1, const Interval& it2){ return interval1.start < interval2.start; } // Need 'static' when placing it in a class
sort(vec.begin(), vec.end(), myComp); // Make comparitor for non-premitive type in class
// Below can replace a 1 line for loop of a vector
accumulate(num.begin(), num.end(), 0, bit_xor<int>());
min_element(num.begin(), num.end(), val) // Return iterator, 
*min_element() // Return value by de-reference
memset(ptr, value, size); // Fill a block of memory. Sets the first num bytes of the block of memory pointed by ptr to the specified value


/* Other */ 
if() --a, ++b, cout << a; // 3 statement in one line (no need bracket)
// They are 128 chars in ascii charset: https://en.wikipedia.org/wiki/ASCII#Character_set


/* Methods */
// Binary search: search sorted
// Newton Iterative method: sqrt()
// Double pointer: Fast & slow pointer in containers like linked list, vector which can be traversed
// Double pointer2: When 1 path doesn't solve (or hard to solve a problem) add another path and compare two path to solve problem: 243:shortest word distance
// Moore voting algorithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm . 169: Majority element
// Construct time series(path related) relationship: 198 house robber
// Sieve of Eratosthenes: Best way to find prime numbers. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes Also, find time complexity of it O(nlgn*lg(lgn))
// Add digits; 1 + (num-1)%9 for all positive number



/* To be solved */ 
// 100. Same Tree: Iterative method
// 104. Maximum depth of binary tree: BFS method
// 107. Binary Tree Level Order Traversal II: Recursive && DFS
// 172. Factorial Tailing zeros
// 204. Count Prime
// 234. Palindrome Linked list
// 256. Paint House
// 257. Binary Tree Path
