class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        def util(i, r):
            if i == n:
                res.append(r[:])
                return
            else:
                r.append(nums[i])
                util(i+1, r)
                r.pop()
                util(i+1, r)
        util(0, [])
        return res
