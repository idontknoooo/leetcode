// 10ms 98%
class Solution {
public:
     int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for (auto& token : tokens) {
        if (token.size() > 1 || isdigit(token[0])) // token is numeric
        {
          st.push(stoi(token));
          continue;
        }
        
        int second = st.top(); st.pop();
        int first  = st.top(); st.pop();
        switch (token[0]) { // token is operator
            case '+': st.push(first + second); break;
            case '-': st.push(first - second); break;
            case '*': st.push(first * second); break;
            case '/': st.push(first / second); break;
        }
      }
      return st.top();
    }
};

// 10ms
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int s1,s2;
        s1=s2=0;
        int res=0;
        for(vector<string>::iterator iter=tokens.begin();iter!=tokens.end();iter++)
        {
                if (*iter == "+")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s1+s2;
                   st.push(res);
                }
                   
                else if (*iter == "-")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s2-s1;
                   st.push(res);
                }
                else if (*iter == "*")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                   res=s1*s2;
                   st.push(res);
                }
                else if (*iter== "/")
                {
                    s1=st.top();
                    st.pop();
                    s2=st.top();
                    st.pop();
                    res=s2/s1;
                    st.push(res);
                }
                else 
                {
                    st.push(atoi((*iter).c_str()));
                }
            }
            return st.top();

    }
};
