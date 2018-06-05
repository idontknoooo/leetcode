// 6ms 99%
class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int i = 0;
        while( s[i] == ' ') s.erase(i, 1);
        
        reverse(s.begin(), s.end());
        
        while( s[i] == ' ') s.erase(i, 1);

        int size = s.size();
        for(i = 0; i < size - 1; i++){
            if( s[i] == ' '){
                if( i == start ){
                    s.erase(i--,1);
                    size--;
                }
                else{
                    reverse(s.begin()+start, s.begin()+i);
                    start = i+1;
                }
            }
        }
        
        reverse(s.begin() + start, s.end());
    }
};

// 6ms
class Solution {
public:
    void reverseWords(string &s) {
        //remove empty spaces
        int i0=0;
        while(i0<(int)s.size()&&s[i0]==' ')i0++;
        s=s.substr(i0);
        while(!s.empty()&&s.back()==' ')s.pop_back();
        int len=s.size(),i=0;
        while(i<len){
            if(i<len&&s[i]==' '){
                s.erase(s.begin()+i);
                len--;
                continue;
            }
            int j=i+1;
            while(j<len&&s[j]!=' ')j++;
            doRev(s,i,j);
            i=j+1;
        }
        doRev(s,0,len);
    }
    void doRev(string& s,int start,int end){
        int left=start,right=end-1;
        while(left<right){
            char ch=s[right];
            s[right]=s[left];
            s[left]=ch;
            left++;
            right--;
        }
    }
};
