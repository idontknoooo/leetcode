// 2ms
class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n + 1, 0);
        t[0] = t[1] = 1;
        int i, j;
        for (i = 2; i <= n; ++i)
        {
            for (j = 1; j <= i / 2; ++j)
                t[i] += t[j - 1] * t[i - j];
            t[i] *= 2;
            if (i % 2)
                t[i] += t[i / 2] * t[i / 2];//Plus the middle 'root' trees.
        }
        return t[n];
    }
};

class Solution {  
public:  
    int numTrees(int n) {  
        int *G = new int[n + 1]();  
        G[0] = 1;  
        G[1] = 1;  
        for(int i = 2; i <= n; i++){  
            for(int j = 0; j < i; j++)  
                G[i] += G[j]*G[i - j - 1];  
        }  
        return G[n];  
    }  
};  
