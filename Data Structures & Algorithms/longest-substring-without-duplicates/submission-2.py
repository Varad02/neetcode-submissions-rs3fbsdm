class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        l = 0
        res = 0

        for i in range(len(s)):
            if s[i] in mp and mp[s[i]] >= l:
                l = mp[s[i]] + 1
            mp[s[i]] = i
            res = max(res, i - l + 1)

        return res