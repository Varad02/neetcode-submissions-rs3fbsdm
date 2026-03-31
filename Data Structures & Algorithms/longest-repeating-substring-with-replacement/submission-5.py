class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        l, r, freq, res = 0, 0, 0, 0
        while l < len(s) and r < len(s):
            count[s[r]]+=1
            freq = max(freq, count[s[r]])
            if r - l + 1 - freq > k:
                count[s[l]]-=1
                l+=1
            res = max(res, r-l+1)
            r+=1
        return res