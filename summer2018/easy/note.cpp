/* Vector */
return {1,2,3} // vector<int> literal without declare 
return {}      // Empty literal
vector<int> vec;
vec['X'] = 1;  // Use character as index


/* Unordered Map */
unordered_map<int, int> um;
if(um.find(kk) != um.end()) // Found (exist in map)


/* string */
string ss = "([{";
if(ss.find('(') != string::npos) // Found (exist in string) 
if(ss.find('(') != -1)           // Same as above 
string::npos // means "until the end of the string". This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type. 
to_string(8); // Convert int, double .. to string


/* Character */
int a = '5' - '0' // Same as 5-0. Char arithematics


/* Edge Case */
// 1. int vs long vs long long
// 2. Negative number
// 3. Zero
// 4. Empty container


/* Bitwise Operation */
int a = 4;
a>>1          // Equal to a/2 = 2;
cout << a>>1; // Illegal (conflict after cout)
int b = a>>1; // Legal. b will equal to 2


/* Notice */
// 1. Reference vs Pointer vs Value


/* Other */
INT_MAX // Max of int in C++, <climits>
INT_MIN // Min of int in C++
size_t  // Could be any unsigned type: unsigned char, unsigned int, unsigned long etc.

/* Methods */
// Binary search: search sorted
// Newton Iterative method: sqrt()
