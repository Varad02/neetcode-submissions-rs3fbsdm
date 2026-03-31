class Solution:
    def climbStairs(self, n: int) -> int:
        self.dp = [0] * (n + 1)
        return self.util(n)

    def util(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        if self.dp[n] != 0:
            return self.dp[n]
        self.dp[n] = self.util(n - 1) + self.util(n - 2)
        return self.dp[n]