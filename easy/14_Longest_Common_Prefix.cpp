class Solution {
public:

    string commonPrefixUtil(string str1, string str2)
    {
        string result = "";
        int n1 = str1.length(), n2 = str2.length();
        // Compare str1 and str2
        for(int i=0; i<n1 && i<n2; i++)
        {
            if (str1[i] != str2[i])
                break;
            result += str1[i];
        }
        return (result);
    }

    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size()>0)
            prefix = strs[0];
        else
            return prefix;
        for (int i=1; i<strs.size(); i++)
            prefix = commonPrefixUtil(prefix, strs[i]);

        return (prefix);
    }
};


