class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.dp = [-1]*len(s)
        return self.util(s, wordDict, 0)

    def util(self, s: str, wordDict: List[str], i: int) -> bool:
        if i == len(s):
            return True
        if self.dp[i] != -1:
            return bool(self.dp[i])
        flag = False
        for word in wordDict:
            if i+len(word) <= len(s) and word == s[i: i+len(word)]:
                flag = self.util(s, wordDict, i+len(word))
                if flag:
                    break
        self.dp[i] = flag
        return flag