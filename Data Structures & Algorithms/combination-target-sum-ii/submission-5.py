class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        res = []
        candidates.sort()
        def util(j, t, r):
            if t < 0:
                return
            if t == 0:
                res.append(r[:])
                return
            for i in range(j, n):
                if candidates[i] > t:
                    break
                if (j < i and candidates[i] == candidates[i-1]):
                    continue
                r.append(candidates[i])
                util(i+1, t-candidates[i], r)
                r.pop()

        util(0, target, [])
        return res