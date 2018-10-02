/* string */
string s(4, '0');  // s == "0000";

/* Method */
/* 
Manacher's algorithm: 5-longest-palindromic-substring.cpp
*/

/* 
Recursion: 
  1. Variable of function (Usually previous state)
  2. End condition (When reach to the last recursion)
  3. Initialization
*/

/*
Use result to find solution
479-largest-palindrome-product.cpp -> find palinedrome then verify whether it is devisiable.
*/

/*
Knuth–Morris–Pratt(KMP) O(m+n) instead O(m*n), which is simply walk through
459-repeated-substring-pattern.cpp
*/

/*
Negative number position marker
448-find-all-numbers-disappeared-in-an-array.cpp
*/

/*
Inorder traverse
501-find-mode-in-Binary-search-tree.cpp
530-minimum-absolute-difference-in-BST.cpp
*/
/*
Depth First Search (DFS)
79-word-search.cpp
94-binary-tree-inorder-traverse.cpp | stack
*/


/*
Relative rank for consecutive number
  Convert number to index index[num[i]] = i;
  Assign increamented number from index.end() to front()
    rank[index[i--]] = rankNum;
    rankNum++;
    this will be the relative rank
506-relative-ranks.cpp
*/
/*
Populating data use recursion
*/
/*
in Loop      slow  --->  fast
Divide 2^8 = 4^4 = 16^2 = 256
*/


/* Bitwise */
// 1. Negate 1 bit = bit ^ 1; 
//     1 ^ 0 = 1, 1 ^ 1 = 0;
//    so   0 ->1 and  1 ->0;
// 476-number-complement.cpp
// 2. a & 1 == 1 -> 'a' is a odd number, it also check the first bit of number 'a'
// 50-pow-x-n.cpp
// 3. Addition for power of 2
// 4 | 2 == 4 + 2 --> 100 | 010 = 100 + 010

/* Time saving technic */
/* 
Math: Sum(i - min) = Sum - n*min
453-minimum-moves-to-equal-array-elements.cpp
*/

/* Map */
m.count(1); // return 1 if key exist otherwise 0
// Map will be automatically sort by key. I tried to rank using lambda function, but I didn't succed even if the code is correct.

/* Standard Library */
min(s.begin()+i, s.end()); // return smallest iterator

/* Combination i & ii
For loop can try all starting point.
Recursion can do exhaustive search and return at a certain point.
Sort is necessary to get no repeat elements (combination ii).
pos: Starting position of search
i  : Current position of search
// Check if start with same element again
// 1 1 1 2 3 | 4->target
// 1 1   2   | case 1
//   1 1 2   | case 2
// 1   1 2   | case 3
We only want case 1, this can be done by recursion. case 2 & 3 are redundent
following help eliminate case 2 & 3
if(i > pos && candidates[i] == candidates[i-1]) continue;
*/

/* Permutation i & ii
Recursively swap each position with other positions will list all posibilities (don't swap with visited position).
For loop can try all starting point.
Recursion can do exhaustive swap for all posible solution.
Sort ins necessary to get no repeat result (permutation ii);
pos: Swap position for current search
i  : Current position which will swap with pos
// If encounter same value as current swap value, don't need to swap
if(i > pos && nums[i] == nums[pos]) continue;
If pass by value, not necessary to swap back i and pos, since all posible value will be pushed duing search so swap back doesn't help.
If pass by reference, may cause repeat
*/

/* Other */
// Reference is much faster than pass by value, since you save time on copying stuff.
// Remind about input size, range are important, they can help you decide what data structure to use to solve problem.


















































