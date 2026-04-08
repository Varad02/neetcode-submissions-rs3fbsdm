class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []

        def util(i):
            if i == n:
                res.append(nums[:])
                return

            for j in range(i, n):
                nums[j], nums[i] = nums[i], nums[j]
                util(i+1)
                nums[j], nums[i] = nums[i], nums[j]

        util(0)
        return res