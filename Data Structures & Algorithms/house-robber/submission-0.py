class Solution:
    def rob(self, nums: List[int]) -> int:
        self.dp = [0] * (len(nums)+1)
        return self.util(nums, 0)
    
    def util (self, nums: List[int], i: int) -> int:
        if i >= len(nums):
            return 0
        
        if self.dp[i] != 0:
            return self.dp[i]
        
        else:
            self.dp[i] = max(nums[i]+self.util(nums, i+2), self.util(nums, i+1))
            return self.dp[i]