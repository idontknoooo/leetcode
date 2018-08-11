# My slow long method
class Solution(object):
    def prefix(self, cur_pf, word):
        res = ""
        if len(word) <= len(cur_pf):
            for idx, letter in enumerate(word):
                if cur_pf[idx] == letter:
                    res += letter
                else:
                    break
        else:            
            for idx, letter in enumerate(cur_pf):
                if word[idx] == letter:
                    res += letter
                else:
                    break
        return res            

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs:
            res = strs[0]
            for word in strs:
                res = self.prefix(res, word)
        else:
            return ""    
        return res
        
# Better method
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        shortest_string = min(strs,key=len) # Find shortest string O(n)
        for i, char in enumerate(shortest_string): # Start from first char
            for string in strs:                    # Make sure each string in strs, has current char
                if string[i] != char:              # Once not equal, done
                    return shortest_string[:i]
        return shortest_string
