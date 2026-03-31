class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        self.dp = [0] * (len(cost) + 1)
        return min(self.util(cost, 0), self.util(cost, 1))

    def util(self, cost: List[int], i: int) -> int:
        if i >= len(cost):
            return 0
        if self.dp[i] != 0:
            return self.dp[i]
        self.dp[i] = cost[i] + min(self.util(cost, i + 1), self.util(cost, i + 2))
        return self.dp[i]