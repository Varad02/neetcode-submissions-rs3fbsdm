class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = float('-inf')
        curr = 1
        for i in nums:
            curr *= i
            res = max(res, curr, i)
            if curr == 0:
                curr = 1
        curr = 1
        for i in reversed(nums):
            curr *= i
            res = max(res, curr, i)
            if curr == 0:
                curr = 1
        return int(res)