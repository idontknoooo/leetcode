// 18ms beat 100%
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int I,J,K,L;
        if(E>C||F>D||A>G||B>H)
            return (C-A)*(D-B)+(G-E)*(H-F);
        else{
            I=max(A,E);
            J=min(C,G);
            K=max(B,F);
            L=min(D,H);
            
        return (C-A)*(D-B)+(G-E)*(H-F)-(J-I)*(L-K);}
    }
};
