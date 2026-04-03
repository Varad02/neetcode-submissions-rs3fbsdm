class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        currMax, currMin = 1, 1
        for n in nums:
            temp = currMax
            currMax = max(n, n*currMax, n*currMin)
            currMin = min(n, n*temp, n*currMin)
            res = max(res, currMax)
        return res