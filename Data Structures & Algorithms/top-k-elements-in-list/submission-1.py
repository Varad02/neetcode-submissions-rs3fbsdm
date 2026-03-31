class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            if num not in count:
                count[num] = 1
            else:
                count[num]+=1
        
        freq = {}
        for num, frequency in count.items():
            if frequency not in freq:
                freq[frequency] = []
            freq[frequency].append(num)
        
        res = []
        for i in range (len(nums), 0, -1):
            if i in freq and k >= len(freq[i]):
                k-=len(freq[i]);
                res.extend(freq[i])
            
        return res