// my solution 8ms beat 66%
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s, s_reverse;
        stringstream ss(path);
        string str = "", ans = "";
        while(getline(ss, str, '/')) {
            if(str == ".." && s.size()) s.pop();
            else if(str == ".." && !s.size()) continue;
            else if(str.length() && str != ".") s.push(str);
        }
        while(s.size()) {
            s_reverse.push(s.top());
            s.pop();
        }
        while(s_reverse.size()) {
            ans += "/" + s_reverse.top();
            s_reverse.pop();
        }
        return !ans.length()? "/" : ans;
    }
};

// 6ms
class Solution {
public:
    string simplifyPath(string path) {
        string results(path);
        stack<int> slash;
        int index = 0;
        int indexResults = 0;
        int n = path.size();
        while(index < n)
        {
            while(path[index] == '/' && index < n) index ++;
            if (n == index) break;

            if(path[index] == '.')
            {
                if (index + 1 == n || path[index + 1] == '/')
                {
                    index += 1;
                    continue;
                }
                else if (index + 1 < n && path[index + 1] == '.')
                {
                    if (index + 2 == n || path[index + 2] == '/')
                    {
                        if (slash.empty())
                        {
                            indexResults = 0;
                        }
                        else
                        {
                            indexResults = slash.top();
                            slash.pop();
                        }
                        index += 2;
                        continue;
                    }
                }
            }
            results[indexResults] = '/';
            slash.push(indexResults);
            indexResults ++;
            while(path[index] != '/' && index < n) results[indexResults++] = path[index++];
        }
        return results.substr(0, max(indexResults, 1));
    }
};
