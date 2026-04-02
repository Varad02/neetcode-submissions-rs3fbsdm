class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        for v, i in enumerate(triplets):
            if i[0] > target[0] or i[1] > target[1] or i[2] > target[2]:
                triplets[v] = triplets[-1]
                triplets.pop()
        f1, f2, f3 = False, False, False
        for i in triplets:
            if i[0] == target[0]:
                f1 = True
            if i[1] == target[1]:
                f2 = True
            if i[2] == target[2]:
                f3 = True
                
        return f1 and f2 and f3