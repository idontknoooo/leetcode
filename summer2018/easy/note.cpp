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

/* For Loop */ 
for(int i = 0; i < 128; ++i) if(a[i]%2) if(++odd > 1) return false;  // One line for loop
for(int i = 0; i < 128; ++i) 
  if(a[i]%2) 
    if(++odd > 1) 
      return false;
// Same as above


/* Iterator */
// Don't iterate from end(), because end() is nullptr, if you want to iterate reversely, use rbegin() != rend()
auto it = set.begin(); 
it + 3 // this is WRONG, you can only do ++it or --it for iterator


/* Vector */
return {1,2,3} // vector<int> literal without declare 
return {}      // Empty literal
vector<int> vec;
vec['X'] = 1;  // Use character as index
// Some questions, you can intialize the size first then add value and add from end to begin: 118-pascals-triangle
vec.back() == vec[vec.size()-1]; // Use vec.back
k %= vec.size() // rotate number cannot more than length of vector
vec.size()-1    // if vec is empty, result is Not -1, it will be 18446744073709551615, since vec.end()==-1
vector<int> vec(100, 0); // Initialize vector of size 100 with all 0, somehow faster than array



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
// To store a specific amount of numbers in order, you don't have to always use vector since it will cause extra calculation, use queue and pop the number that will never be used. 346-moving-average-from-data-stream


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
// Following are not equal
int tmp = um.find(s[i])==um.end()? i : -1;
um[s[i]] = tmp;
//if(um.find(s[i])==um.end()){
//    um[s[i]] = i;
//} else {
//    um[s[i]] = -1;
//}
// Return max value
string val = (*max_element(um.begin(), um.end(), [](auto p1, auto p2){return p1.second < p2.second;})).second;
// Return max key
string val = (*max_element(um.begin(), um.end(), [](auto p1, auto p2){return p1.second < p2.second;})).first;


/* Unordered_multimap */
// 734-sentence-similarity
unordered_multimap<string, string> umm;
umm.insert(pair<string, string> ("A", "X"); // there is no [] for multimap, insert a pair, pair->first is key, pair->second is value
pair <unordered_multimap<string,string>::iterator, unordered_multimap<string,string>::iterator> er = umm.equal_range("A"); // return a range of values which has key "A"
// er.first: lower bound of equal_range, er.second: upper bound of equal_range
for(unordered_multimap<string, string>::iterator it = er.first; it != er.second; ++it){
  cout << it.second << endl; // print all values for key "A"
}


/* Pairs */
pair<string, string> p = pair<string, string> ("A", "X");
auto p1 = pair<string, string> (p.second, p.first); // switch first & second and make a new pair
p = make_pair("B", "Y"); // use make_pair



/* string */
string ss = "([{";
if(ss.find('(') != string::npos) // Found (exist in string) 
if(ss.find('(') != -1)           // Same as above 
string::npos // means "until the end of the string". This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type. 
to_string(8); // Convert int, double .. to string
// Add to back of a string is faster than add to front of a string
s.append(" ") // same as below
s += " ";     // Fast
s  = " " + s; // Slow
// Check whether string has all same letter
a = "bbbbbb";
if(a.find_first_not_of(a[0]) == string::npos) 
  cout << "All same" << endl;
else
  cout << "Not all same" << endl;


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
// Pre-order : root->left->right
/*
void preorder(TreeNode* root){
  if(root){
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
  }
}
*/
// In-order  : left->root->right
/*
void inorder(TreeNode* root){
  if(root){
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
  }
}
*/
// Post-order: left->right->root
/*
void postorder(TreeNode* root){
  if(root){
    postorder(root->left);
    postorder(root->right);
    cout << root->val << endl;
  }
}
*/
// When need access multiple nodes on same level, you can use vector to store level and corresponding value and pre-order traverse: 637-average-level-binary-tree

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
a>>2          // a/2/2 = a/4 = 1
a<<1          // Equal to a*2 = 8; Also, remove most left bit and add 0 from most right bit
cout << a>>1; // Illegal (conflict after cout)
int b = a>>1; // Legal. b will equal to 2
int tmp = a^a           // return 0, since a==a
int tmp = 0^a           // return a. 1^0->1, 0^0->0
n &= n-1      // Change 1 bit at a time, make bit with value 1 to 0 one by one. 1 will become to 0 by &, and no new '1' will occur
n & 1         // Only keep most right bit and ingore all other bit
if(a==b) 
if(!(a^b))    // Faster than above when a and b are integers
// Binary of power of 4
/*
001   - 1
100   - 4
10000 - 16
10^8  - 64
...
If x is power of 4, then x&(x-1)==0
If x is power of 4, then (x-1)%3==0
*/
// How to check all bits are 1s
int a = 7; // 111
return !(a & a+1); // 111 & 1000 -> 0; !0 -> 1


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
if('0' <= S[i] && S[i] <= '9') // Same as above
isalnum() // Check if it's letter or number
sort(vec.begin(), vec.end());// Sort vector
static bool myComp(const Interval& it1, const Interval& it2){ return interval1.start < interval2.start; } // Need 'static' when placing it in a class
sort(vec.begin(), vec.end(), myComp); // Make comparitor for non-premitive type in class
// Below can replace a 1 line for loop of a vector
accumulate(num.begin(), num.end(), 0, bit_xor<int>());
// for loop is faster than accumulate!!!
min_element(num.begin(), num.end(), val) // Return iterator, 
*min_element() // Return value by de-reference
memset(ptr, value, size); // Fill a block of memory. Sets the first num bytes of the block of memory pointed by ptr to the specified value
isupper(x) // same as x < 97 when given input are only letters
islower(x) // same as x >= 97 when given input are only leters
reverse(s.begin(), s.end()); // Reverse can be used on string & vector etc using iterator
size_t // Unsigned integral type
string::size_type sc; // alias of size_t
stoi(str_dec, &sz);   // to decimal
stoi(str_hex, nullptr, 16); // to hex
stoi(str_auto, nullptr, 0); // auto



/* Bitset */
bitset<10> bs; // Bitset of size 10
// Set start from left most bit
bs.set();      // Set all bits as 1
bs.set(1);     // Set second bit as 1
bs.set(1,1);   // Set second bit as 1
bs.set(1,0);   // Set second bit as 0
bs.test(1);    // Check whether position 1 has value 1
bitset<10> bs (std::string("1011"));
bs.reset(0)    // Reset set bit to 0, start from right most bit
bs.count()     // return the number of set bits (value==1)


/* Stream */
// To separate string inside of a string use "istringstream"
string str = "ab cd";
istringstream in(str);
while(in >> word) cout << word << endl; // will print ab, cd
while(getline(in, word, ' ')) cout << word << endl; // also works

/* Other */ 
if() --a, ++b, cout << a; // 3 statement in one line (no need bracket)
// They are 128 chars in ascii charset: https://en.wikipedia.org/wiki/ASCII#Character_set
// Number ascii code: [48, 57]
// Capital letter: [65, 90]
// Lower letter: [97, 122]
// Sum between 0, a = a(a-1)/2
// Sum between a, b = (b-a)(a+b-1)/2
// (a+b)/2 is NOT same as a+(b-a)/2 since the first one might overflow integer to long, second one won't
// Find if x is power of 3, if x is an integer, find the max power of 3 that is an integer, say m = 3^max, if m%x==0 and x >0 then, x is power of 3.
//    3^max / n^num = 3^(max-num) = Integer
// Perfect square:
//  n^2 - (n-1)^2 = 2n-1
//  n^2 = 2n-1 + (n-1)^2
// two's complements for negative number -1
//  !1 + 1 = !(001) + 1 = 110 + 1 = 111
// -1 * a is faster than -a, when 'a' is a number
// You can use private member to replace lack of parameter in function
/*
class Test {
  int hh = 0;
public:
  void a(int num){
    hh += num;
  }
  
  // Same as above
  void b(int num, int& hh){ 
    hh += num;
  }
};
*/
// Recreate variable takes time
for(int a = 0; a < 3; ++a)
  for(int b = a; b < 5; ++b);
// Faster than above, since didn't recreate b
int a = 0, b = -1
for(a = 0; a < 3; ++a)
  for(b = a; b < 5; ++b);
// 'a' <= => 'A' toggle lower & upper
'a' ^= (1 << 5) // 'a' ^= 0b100000 // ->32 
'a' // 65 1000001
'A' // 97 1100001 
'A' - 'a' // 100000

/* Methods */
// Binary search: search sorted
// Newton Iterative method: sqrt()
// Double pointer: Fast & slow pointer in containers like linked list, vector which can be traversed
// Double pointer2: When 1 path doesn't solve (or hard to solve a problem) add another path and compare two path to solve problem: 243:shortest word distance
// Double pointer3: Continously replace element in vector: 283-move-zeres
// Moore voting algorithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm . 169: Majority element
// Construct time series(path related) relationship: 198 house robber
// Sieve of Eratosthenes: Best way to find prime numbers. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes Also, find time complexity of it O(nlgn*lg(lgn))
// Add digits; 1 + (num-1)%9 for all positive number
// Most dynamic programming questions need math induction!
// Displace错位: When traverse array, and situation are symmtrical on left & right, displace to either left or right to simplify situation. 665-non-decreasing-array.cpp



/* Logic */ 
// Always think about Math: mathematic way is more efficient than computer science way



/* To be solved */ 
// 100. Same Tree: Iterative method
// 104. Maximum depth of binary tree: BFS method
// 107. Binary Tree Level Order Traversal II: Recursive && DFS
// 172. Factorial Tailing zeros
// 204. Count Prime
// 234. Palindrome Linked list
// 256. Paint House
// 257. Binary Tree Path
// 371. Integer Sum
// 437. Path Sum III
// 746. Min cost climbing stairs (Dynamic Programming)
// 758. Bold words in string
// 784. Letter Case Permutation
// Tree Traverse: Inorder, postorder, etc.
// BFS on Tree, DFS on Tree
// Heap sort
// Other sort
