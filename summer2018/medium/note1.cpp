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
