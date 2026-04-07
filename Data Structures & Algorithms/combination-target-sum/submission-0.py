class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []

        def util(i, t, r):
            if t < 0:
                return
            if t == 0:
                res.append(r.copy())
                return
            for j in range(i, n):
                r.append(nums[j])
                util(j, t-nums[j], r)
                r.pop()

        util(0, target, [])
        return res