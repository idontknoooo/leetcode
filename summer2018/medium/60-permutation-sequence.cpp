// 7ms
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n+1, 1); string s(n, '0');
        vector<bool> used(n, false); k--;
        for(int i=1; i<=n; i++)
            fac[i] = fac[i-1]*i;
        for(int i=0; i<n; i++){
            int p = k / fac[n-i-1] + 1, t = 0, c = 0;
            for(t=0; t<n; t++){
                if(!used[t]) c++;
                if(c == p) break;
            }
            s[i] += (t+1); used[t] = true; k %= fac[n-i-1];
        }
        return s;
    }
};


// 6ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; i++) factorial[i] = factorial[i - 1] * i;
        k--; // if k = 1, 0 / factorial[i - 1] = 0
        for (int i = n; i >= 1; i--){
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};
