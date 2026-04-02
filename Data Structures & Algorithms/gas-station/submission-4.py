class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gasSum = sum(gas)
        costSum = sum(cost)
        if gasSum < costSum:
            return -1
        res = 0
        total = 0
        for i in range(len(cost)):
            total += gas[i]-cost[i]
            if total < 0:
                total = 0
                res = i+1
        return res