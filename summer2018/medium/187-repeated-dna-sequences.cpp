// 10ms
//  https://leetcode.com/problems/repeated-dna-sequences/discuss/53952/20-ms-solution-(C++)-with-explanation

class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10)
        return vector<string>();
        
    vector<string> R;
    bitset<1<<20> S1;
    bitset<1<<20> S2;
    
    int val = 0;
    for (int i=0; i < 10; i++)   // Calc. the has value for the first string.
        val = (val << 2) | char2val(s[i]);
    S1.set(val);
    cout << val << " | ";
    
    int mask = (1 << 20) - 1;
    for (int i=10; i < s.size(); i++) {
        // Calc the hash value for the string ending at position i.
        val = ((val << 2) & mask) | char2val(s[i]);  
        if (S2[val])
            continue;
        if (S1[val]) {
            R.push_back(s.substr(i-10+1, 10));
            S2.set(val);
        }
        else
            S1.set(val);
    }
    return R;
}

int char2val(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
 }
};

// 8ms
class Solution {
public:
   vector<string> findRepeatedDnaSequences(string s) {
    char flag[262144] ={0};
    vector<string> result;
    int len,DNA=0,i;
    if((len=s.length())< 11) return result;
    for(i = 0 ; i < 9; i++)
        DNA = DNA << 2| (s[i] - 'A' + 1) % 5;
    for(i = 9;i<len;i++)
    {
        DNA = (DNA<<2 & 0xFFFFF)|(s[i] - 'A' + 1)%5;
            if(!(flag[DNA>>2]&(1<<((DNA&3) << 1)))) 
                flag[DNA>>2] |= (1<<((DNA&3) << 1));
            else if(!(flag[DNA>>2]&(2<<((DNA&3) << 1)))) 
            {
                result.push_back(s.substr(i-9,10));
                flag[DNA>>2] |= (2<<((DNA&3) << 1));
            }
    }
    return result;
}
};

// 7ms
class Solution {
public:
    /* Each character could be represented by two bits
 * since there are only 4 possibilities.
 */
int toInt(char c) {
    switch(c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            return 0;
    }
}
    
vector<string> findRepeatedDnaSequences(string s) {
    static const int L = 10;
    static const int mask = 0xfffff;
    
    vector<string> v;
    if(s.size() <= L) return v;

    /* One char could be represented by 2 digits, and s is 10-char long,
     * there are at most 2^20 possible values.
     */
    bitset<1<<20> isThere;  // is the string present?
  bitset<1<<20> isMultiple;   // are there multiple occurencies for the same string?
  
    int hash = 0;
    for(int i = 0; i < L; ++i) {
        // shift the hash 2 bits to the left to discard the most significant bit,
        // then append the current digit to it
        hash = (hash << 2) | toInt(s[i]);
    }
  isThere.set(hash);
    
  for(int i = L; i < s.size(); ++i) {
        // keep 20 digits only and append the current digit to it
    hash = ((hash << 2) & mask) | toInt(s[i]);  
    if(isThere[hash] == 0) {
      isThere.set(hash);
    } else if(isThere[hash] && isMultiple[hash] == 0) {
      v.push_back(s.substr(i - L + 1, L));
      isMultiple.set(hash);
    }
  }
  
  return v;
}
};
