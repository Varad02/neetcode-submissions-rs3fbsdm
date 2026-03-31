class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        if money - (sorted(prices)[0] + sorted(prices)[1]) >= 0:
            return money - (sorted(prices)[0] + sorted(prices)[1])
        else:
            return money