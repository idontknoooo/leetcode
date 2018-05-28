// My solution 35ms
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.find(B)!=-1) return 1;
        int count = B.length() / A.length();
        count = count < 1? 1 : count;
        string a1 = A, a2 = "", a3 = "";
        for(int i = 0; i < count-1; ++i){
            a1.append(A);
        }
        a2 = a1;
        a2.append(a1);
        a3 = a2;
        a3.append(a2);
        if(a1.find(B)!=-1) return count;
        if(a2.find(B)!=-1) return count+1;
        if(a3.find(B)!=-1) return count+2;
        return -1;
    }
};

// 6ms solution
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // 思路1：i代表每次循环开始，A开始的位置（设想"abcd"、"cdabcd", 只有i=2才有可能比对成功）
        /*for(int i = 0, j = 0; i < (int)A.size(); i++, j=0) {
            while(j==-1 || (j < (int)B.size() && A[(i+j)%A.size()]==B[j])) ++j;
            if(j == B.size()) {
                // 此时 i 为 A 开始比对的位置，j显然是B的长度，如：
                // A="abcd", B="cdabcdab", 则i=2, j=B.size()=8，可以发现刚好补上了前面的值，所以只需要判断是否有余数即可
                return (i+j)/A.size()+((i+j)%A.size()!=0?1:0);

            }
        }*/
        
        vector<int> next(B.size() + 1);
        next[0] = -1;
        for(int i = 0, j = -1; i < B.size(); ) {
            if(j == -1 || B[j] == B[i]) next[++i] = ++j;
            else j = next[j];
        }
        
        // 思路2：i的含义与思路1相同，代表每次循环开始，A开始的位置（哪怕是i=j-next[j]）。
        //       当next[j]>=0时，此时意味着j可以跳过某些重复比对，直接从next[j]开始。
        //       
        //       关键在于：如何判断无论如何加倍A,也无法构成题目要求的串？
        //               当i>=A.size()时，则可以认为无需再比对下去。因为如果i>=A.size(),其实取模后的值本应该早就比对过了
        for(int i = 0, j = 0; i < (int)A.size(); i+=max(1,j-next[j]), j=next[j]) {
            while(j==-1 || (j < (int)B.size() && A[(i+j)%A.size()]==B[j])) ++j;
            if(j == B.size()) {
                // 此时 i 为 A 开始比对的位置，j显然是B的长度，如：
                // A="abcd", B="cdabcdab", 则i=2, j=B.size()=8，可以发现刚好补上了前面的值，所以只需要判断是否有余数即可
                return (i+j)/A.size()+((i+j)%A.size()!=0?1:0);

            }
        }
        return -1;
    }
};


// 5ms
class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    string tmp = A + A;
    size_t pos = tmp.find(B.substr(0, A.size()));
    if(pos == string::npos)
      return -1;

    int count = 1;
    size_t i = 0;
    while(i < B.size()) {
      if(pos == A.size()) {
        pos = 0;
        ++count;
      }
      if(A[pos++] != B[i++])
        return -1;
    }
    return count;
  }
};
