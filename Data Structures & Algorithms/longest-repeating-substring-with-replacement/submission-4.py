class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        l, r, freq, res = 0, 0, 0, 0
        while l < len(s) and r < len(s):
            mp[s[r]]+=1
            freq = max(freq, mp[s[r]])
            if r - l + 1 - freq > k:
                mp[s[l]]-=1
                l+=1
            res = max(res, r-l+1)
            r+=1
        return res