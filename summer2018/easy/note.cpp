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


/* Stack */
// Time series min_stack method: 155: Min stack


/* Unordered Map */
unordered_map<int, int> um;
if(um.find(kk) != um.end()) // Found (exist in map)
um[kk] // Return 0 if doesn't exist, BUT if the value is 0, then there is a misleading singal
if(um[kk])                  // Exist, but it will missing when value is 0
if(!um[kk])                 // NOT "Not Found", since it might because the value is 0
// For sorted vector, you no need unordered map



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


/* Linked List */
// Double pointer: slow vs fast to detect whether there is a cycle


/* Edge Case */
// 1. int vs long vs long long
// 2. Negative number
// 3. Zero
// 4. Empty container


/* Bitwise Operation */
int a = 4;
a>>1          // Equal to a/2 = 2;
a<<1          // Equal to a*2 = 8;
cout << a>>1; // Illegal (conflict after cout)
int b = a>>1; // Legal. b will equal to 2
int tmp = a^a           // return 0, since a==a
int tmp = 0^a           // return a. 1^0->1, 0^0->0


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
// Below can replace a 1 line for loop of a vector
accumulate(num.begin(), num.end(), 0, bit_xor<int>());
min_element(num.begin(), num.end(), val) // Return iterator, 
*min_element() // Return value by de-reference


/* Other */ 
if() --a, ++b, cout << a; // 3 statement in one line (no need bracket)

/* Methods */
// Binary search: search sorted
// Newton Iterative method: sqrt()
// Double pointer: Fast & slow pointer in containers like linked list, vector which can be traversed
// Moore voting algorithm: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm . 169: Majority element


/* To be solved */ 
// 100. Same Tree: Iterative method
// 104. Maximum depth of binary tree: BFS method
// 107. Binary Tree Level Order Traversal II: Recursive && DFS
// 172. Factorial Tailing zeros
