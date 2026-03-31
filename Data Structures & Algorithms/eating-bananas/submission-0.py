class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = r

        while l <= r:
            k = (r+l) // 2
            totalT = 0
            for pile in piles:
                totalT += math.ceil(float(pile)/k)
            if totalT <= h:
                res = k
                r = k-1
            else:
                l = k+1
        return res