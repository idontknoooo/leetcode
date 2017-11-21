class Solution {
public:
    int countPrimes(int n) {
        // if(n<=2) return 0;
        // else if(n<=3) return 1;
        // else if(n<5) return 2;
        // vector<int> num;
        // int count = 2;
        // for(int i = 5; i < n; i+=2)
        // {
        //     int j = 2;
        //     for(j = 3; j<=sqrt(i); ++j)
        //     {
        //         //cout << i%j << endl;
        //         if(!(i%j))
        //         {j=1; break;}
        //     }
        //     if(j > sqrt(i))
        //         ++count;                
        // }
        // return count;
        // vector<bool> prime(n, true);
        // prime[0] = false, prime[1] = false;
        // for (int i = 0; i < sqrt(n); ++i) {
        //     if (prime[i]) {
        //         for (int j = i*i; j < n; j += i) {
        //             prime[j] = false;
        //         }    
        //     }    
        // }
        // return count(prime.begin(), prime.end(), true);
        //  bool flag[n+1];
        // memset(flag,true,sizeof(flag));
        // for(int i=2;i*i<n;i++)
        // {
        //     if(flag[i])
        //         for(int j=i;j*i<n;j++)
        //             flag[i*j]=false;
        // }
        // int ans=0;
        // for(int i=2;i<n;i++)
        //     if(flag[i]==true)
        //         ans++;
        // return ans;
        
        if (n < 3) return 0;
        bool A[n];
        int count = 1;
        memset(A, false, sizeof(A));
        for(int i=3; i<n; i+=2) {
            if (!A[i]) {
                count++;
                for(long long j = (long long)i*i; j<n; j+=2*i) A[j] = true;
            }
        }
        return count;
        
    }
};