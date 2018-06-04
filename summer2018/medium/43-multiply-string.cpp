// My super slow 180ms solution, beat 2%
// Use addition
class Solution {
public:
    string addition(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0) {
            int tmp = carry;
            if(i >= 0) tmp += num1[i--] - '0';
            if(j >= 0) tmp += num2[j--] - '0';
            carry = tmp>9? 1 : 0;
            ans.append(to_string(tmp%10));
        }
        if(carry) ans.append("1");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        int mul = 1;
        string ans = "0";
        for(int i = num1.length() - 1; i >= 0; --i) {
            int times = num1[i] - '0';
            string tmp = "";
            if(times > 0) tmp = num2;
            while(times > 1) {
                tmp = addition(tmp, num2);
                --times;
            }
            int times1 = mul;
            while(times1 > 1 && tmp[0] != '0') {
                tmp += "0";
                --times1;
            }
            ans = addition(ans, tmp);
            ++mul;
        }
        return ans;
    }
};

// 8ms solution
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if(m == 0 || n == 0) return "";
        string res(m+n, '0');
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i = 0; i < m; ++i) {
            int r = 0;
            for(int j = 0; j < n; ++j) {
                int tmp = (res[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + r; 
                res[i + j] = tmp % 10 + '0';
                r = tmp / 10;
            }
            res[i+n] += r; 
        }
        
        reverse(res.begin(), res.end());
        
        size_t pos = res.find_first_not_of("0");  
        if(pos != string::npos)  
            return res.substr(pos);  
  
        return "0";  
    }
};

// 10ms
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int j=0; j<num2.size(); j++) {
            int carry=0, val=num2[j]-'0';
            for (int i=0; i<num1.size(); i++) {
                int tmp=res[i+j]-'0'+carry+val*(num1[i]-'0');
                res[i+j]=tmp%10+'0';
                carry=tmp/10;
            }
            if(carry>0) res[j+num1.size()]=carry+'0';
        }
        while(res.back()=='0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};


// 9 ms
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        for(int i = num1.size() -1; i>=0; --i) {
            int carry = 0;
            for(int j = num2.size()-1; j>=0; --j) {
                int tmp = (sum[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0')+carry;
                sum[i+j+1] = tmp%10 + '0';
                carry = tmp/10;
            }
            sum[i] += carry;
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if(string::npos != startpos)
            return sum.substr(startpos);
        return "0";
    }
};
