class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0
        for i in range(len(nums)):
            maxIndex = max(maxIndex, i+nums[i])
            if maxIndex >= len(nums)-1:
                return True
            while maxIndex < len(nums) and nums[maxIndex] == 0:
                maxIndex-=1
            if maxIndex <= i:
                return False