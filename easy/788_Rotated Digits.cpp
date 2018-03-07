class Solution {
public:
    int rotate(int N, unordered_map<int,int> m){
        int i = 0;
        int re = 0;
        while(N > 0){
            int tmp = N%10;
            if(m.find(tmp)==m.end()){
                return -1;
            } else {
                tmp = m[tmp];
            }
            N /= 10;
            int ex = pow(10, i);
            re += ex * tmp;
            i++;
        }
        return re;
    }
    int rotatedDigits(int N) {
        unordered_map<int, int> m = {{1,1},{0,0},{2,5},{5,2}, {6,9}, {9,6}, {8,8}};
        int count = 0;
        for(int i = 1; i <= N; ++i){
            int tmp = rotate(i, m);
            // cout << tmp << endl;
            if(tmp!=-1 && tmp != i)
                ++count;
        }
        return count;
    }
};
