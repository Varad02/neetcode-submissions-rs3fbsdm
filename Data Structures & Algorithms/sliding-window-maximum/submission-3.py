class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = []
        for i in range(k):
            heapq.heappush(heap, [-nums[i], i])
        res = []
        l = 0
        for i in range(k, len(nums)+1):
            while heap[0][1] < l:
                heapq.heappop(heap)
            res.append(-heap[0][0])
            if i==len(nums):
                break
            heapq.heappush(heap, [-nums[i], i])
            l+=1
        return res