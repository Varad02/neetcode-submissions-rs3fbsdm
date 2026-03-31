class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""
        resLen = float("inf")
        resL = 0
        tCount = defaultdict(int)
        sCount = defaultdict(int)
        for ch in t:
            tCount[ch]+=1
        l, r = 0, 0
        have = 0
        need = len(tCount.values())
        for r in range(len(s)):
            sCount[s[r]] += 1
            if sCount[s[r]] == tCount[s[r]]:
                have+=1
            while have == need:
                if r - l + 1 < resLen:
                    resLen = r - l + 1
                    resL = l
                if s[l] in tCount and sCount[s[l]] == tCount[s[l]]:
                    have-=1
                sCount[s[l]]-=1
                l+=1

        return s[resL : resL + resLen] if resLen != float("inf") else ""
