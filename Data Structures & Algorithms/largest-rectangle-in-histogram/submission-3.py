class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        leftLow = [0] * n
        rightLow = [0] * n
        stack = [0]
        for i in range(1, n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            leftLow[i] = stack[-1]+1 if stack else 0
            stack.append(i)
        stack = [n-1]
        rightLow[n-1] = n-1
        for i in range(n-2, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            rightLow[i] = stack[-1]-1 if stack else n-1
            stack.append(i)
        res=0
        for i in range(n):
            res=max(res, heights[i]*(rightLow[i]-leftLow[i]+1))
        return res