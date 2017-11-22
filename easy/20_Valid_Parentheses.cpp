// g++ -std=c++11 20*
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        string ss = "([{";
        stack<char> sc;
        for(char& c : s)
        {
            if(ss.find(c)!=string::npos)
                sc.push(c);
            else
            {
				// Use Ascii to check whether they match
                if(sc.empty() || (sc.top()+1 != (int)c && sc.top()+2 != (int)c))
                    return false;
                else
                    sc.pop(); 
            }
        }
        return sc.empty()? true : false;
    }
};
int main()
{
	string s = "(){}[][";
	Solution so;
	cout <<	so.isValid(s) << endl;	
	return 0;
}
// Straight forward method
bool isValid(string s){
    map<char, char> m = {
        {'{','}'}, {'(',')'}, {'[',']'}
    };
    stack<char> p;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            p.push(s[i]);
        else if(p.size()){
            if(m[p.top()] == s[i])
                p.pop();    
            else break;
        }
        else
            return false;
    }
    return p.size()==0? true : false;
}