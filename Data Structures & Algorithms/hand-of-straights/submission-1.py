class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        
        freq = defaultdict(int)
        for card in hand:
            freq[card] += 1
        
        for card in sorted(freq):
            count = freq[card]
            if count > 0:
                for i in range(groupSize):
                    if freq[card + i] < count:
                        return False
                    freq[card + i] -= count
        return True