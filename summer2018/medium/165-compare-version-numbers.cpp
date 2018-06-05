// 2ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        // create stringstreams for versions
        stringstream ss1(version1); 
        stringstream ss2(version2);
        // variables to store version values
        int v1 =0;
        int v2 =0;
        char c; // character to get . from versions
        while(ss1 || ss2){
            ss1 >> v1; // try to get int value from version1
            ss2 >> v2; // try to get int value from version2
            // if ss1 and ss2 both are invalid now, it means we did not get any valid value for v1 and v2. It means we are done comparing versions and till this point versions were same. Return 0. 
            if(!ss1 && !ss2) return 0; 
            // if ss1 was not valid, it means we failed to get v1. Make v1 = 0 , to be able to compare version like 1.2 and 1.2.0
            if(!ss1) v1=0;
            // if ss2 was not valid, it means we failed to get v2. Make v2 = 0 , to be able to compare version like 1.2.0 and 1.2
            if(!ss2) v2=0;
            // Now compare v1 and v2 according to given rules and give result if they are different.
            if(v1 > v2) return 1;
            if(v2 > v1) return -1;
            // Reaching here means v1 and v2 are same. In that case we need to loop again to be able to compare next version numbers. Get . char from valid stringstreams so that we can extract integer version numbers in next loop iteration.
            if(ss1) ss1 >> c;
            if(ss2) ss2 >> c;
        }
        return 0;
    }
};

// 2ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int n1= version1.size();
        int n2 = version2.size();
        int v1 = 0;
        int v2 = 0;
        while(i < n1 || j < n2){
            
            for(; i<n1 && version1[i] != '.';i++ )
                v1 = v1*10 + version1[i]-'0';
            for(;j<n2&&version2[j]!='.';j++)
                v2 = v2*10 + version2[j]-'0';
            int comp = v1 - v2 ;
            if(comp != 0)
                return comp >0 ? 1 : -1;
            v1=v2=0;
            i++;
            j++;
            
        }
        
        return 0;
    }
};
