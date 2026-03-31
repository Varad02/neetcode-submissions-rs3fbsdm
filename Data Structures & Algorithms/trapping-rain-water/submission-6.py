class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        # fix initialization
        maxRight = [[0, 0] for _ in range(n)]
        maxRight[-1] = [height[-1], n - 1]
        for i in range(n - 2, -1, -1):
            maxRight[i] = max([height[i], i], maxRight[i + 1])
        maxLeft = [height[0], 0]
        for i in range(1, n):
            maxLeft = max(maxLeft, [height[i], i])
            # fix index here: maxRight[i][0], not maxRight[0]
            res += min(maxLeft[0], maxRight[i][0])-height[i]
        return res