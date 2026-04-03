class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        currMax, currMin = 1, 1
        for n in nums:
            currMax, currMin = max(n, n*currMax, n*currMin), min(n, n*currMax, n*currMin)
            res = max(res, currMax)
        return res