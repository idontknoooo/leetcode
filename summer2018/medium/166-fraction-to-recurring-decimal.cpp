// 2ms
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        long long int numer=numerator;
        long long int denum=denominator;
        int sign=1;
        if(numer<0){
            sign*=-1;
            numer*=-1;
        }
        if(denum<0){
            sign*=-1;
            denum*=-1;
        }
        long long int IntPart=numer/denum;
        numer%=denum;
        if(numer==0)return (sign>0? "":"-")+to_string(IntPart);
        string DecPart="";
        unordered_map<long long int,int> map;
        int idx=0;
        while(!map.count(numer)){
            map[numer]=idx++;
            numer*=10;
            int nextdigit=numer/denum;
            DecPart+='0'+nextdigit;
            numer%=denum;
            if(numer==0)return (sign>0? "":"-")+to_string(IntPart)+"."+DecPart;
        }
        DecPart.insert(DecPart.begin()+map[numer],'(');
        DecPart+=")";
        return (sign>0? "":"-")+to_string(IntPart)+"."+DecPart;
    }
};

// 3ms
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long n = labs(numerator), d = labs(denominator);
        
        string result;
        bool negative = (denominator > 0 ^ numerator > 0);
        if (negative) result += "-";
        
        if (n % d == 0) {
            result += to_string(n/d);
            return result;
        } 
            
        result += to_string(n/d) + ".";
        n = n%d;
        
        unordered_map<int,int> mapping;
        while (n) {
            if (mapping.find(n) == mapping.end()) {
                mapping[n] = result.length();
                n *= 10;
                result += to_string(n/d);
                n = n%d;
            } else {
                result.insert(mapping[n], 1, '(');
                result += ")";
                break;
            }
        }
        return result;
    }
};

