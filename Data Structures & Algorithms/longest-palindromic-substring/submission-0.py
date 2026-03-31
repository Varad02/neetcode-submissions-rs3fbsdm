class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            l, k = i, i
            while l >= 0 and k < len(s) and s[l]==s[k]:
                l-=1
                k+=1
            if len(res) < k - 1 - l:
                res = s[l+1: k]
            l, k = i, i+1
            while l >= 0 and k < len(s) and s[l]==s[k]:
                l-=1
                k+=1
            if len(res) < k - 1 - l:
                res = s[l+1: k]
        return res