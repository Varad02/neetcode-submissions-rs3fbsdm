class Solution:
    def countSubstrings(self, s: str) -> int:
        res = []
        for i in range(len(s)):
            l, k = i, i
            while l >= 0 and k < len(s) and s[l]==s[k]:
                res.append(s[l+1: k])
                l-=1
                k+=1
            l, k = i, i+1
            while l >= 0 and k < len(s) and s[l]==s[k]:
                res.append(s[l+1: k])
                l-=1
                k+=1
        return len(res)