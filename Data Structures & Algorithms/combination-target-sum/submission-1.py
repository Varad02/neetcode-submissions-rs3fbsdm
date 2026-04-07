class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []

        def util(i, t, r):
            if t == 0:
                res.append(r.copy())
                return
            if t < 0 or i == n:
                return
            r.append(nums[i])
            util(i, t-nums[i], r)
            r.pop()
            util(i+1, t, r)
        
        util(0, target, [])
        return res