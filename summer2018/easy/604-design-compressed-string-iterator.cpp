// 14ms
class StringIterator {
    char c;
    int count = 0;
    string::iterator i;
    string str;
public:
    StringIterator(string compressedString) {
        str = compressedString;
        i = str.begin();
    }
    
    char next() {
        if (hasNext()) {
            --count;
            return c;
        }
        else
            return ' ';
    }
    
    bool hasNext() {
        if (count > 0)
            return true;
        if (i == str.end())
            return false;
        else {
            c = *i;
            count = 0;
            ++i;
            while (i != str.end() && *i >= '0' && *i <= '9') {
                count *= 10;
                count += *i - '0';
                ++i;
            }
            return true;
        }
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */


//16ms
class StringIterator {
public:
    StringIterator(string compressedString) {
        int num = 0;
        char c;
        for(int i = 0;i<compressedString.size();i++)
        {
            if(!isdigit(compressedString[i]))
            {
                if(num!=0) q.push({c,num});
                num = 0;
                c = compressedString[i];
            }
            else
                num = num*10+compressedString[i]-'0'; 
        }
        if(num!=0) q.push({c,num});
    }
    
    char next() {
        if(!hasNext()) return ' ';
        char val = q.front().first;
        q.front().second--;
        if(q.front().second==0)q.pop();
        return val;
    }
    
    bool hasNext() {
        return q.size()>0?true:false;
    }
private:
    queue<pair<char,int>> q;
    bool isdigit(char c)
   {
       return c>='0'&&c<='9';
   }
};
