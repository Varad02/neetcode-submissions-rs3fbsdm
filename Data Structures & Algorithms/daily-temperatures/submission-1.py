class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = deque()
        res1 = [0] * len(temperatures)
        res.append(len(temperatures) - 1)
        for i in range(len(temperatures)-2, -1, -1):
            while res and temperatures[i] >= temperatures[res[-1]]:
                res.pop()
            res1[i] = res[-1]-i if res else 0
            res.append(i)
        return res1
        