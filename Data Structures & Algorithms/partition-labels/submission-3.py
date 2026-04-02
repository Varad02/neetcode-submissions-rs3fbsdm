class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ranges = defaultdict(list)
        for i, ch in enumerate(s):
            if ranges[ch]:
                ranges[ch][1] = i
            else:
                ranges[ch] = [i, i]
        intervals = self.merge_intervals(sorted(ranges.values()))
        res = []
        for _, [i, j] in enumerate(intervals):
            res.append(j-i+1)
        return res


    def merge_intervals(self, intervals: List[List[int]]):
        if not intervals:
            return []
        merged = [intervals[0]]

        for start, end in intervals[1:]:
            last_end = merged[-1][1]

            if start <= last_end:
                merged[-1][1] = max(last_end, end)
            else:
                merged.append([start, end])

        return merged
