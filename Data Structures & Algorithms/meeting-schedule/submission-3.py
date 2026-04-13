"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> int:
        start = [s.start for s in intervals]
        end   = [e.end for e in intervals]
        start.sort()
        end.sort()
        s, e = 0, 0
        count, res = 0, 0
        while s < len(intervals) and e < len(intervals):
            if end[e] > start[s]:
                s+=1
                count+=1
            else:
                e+=1
                count-=1
            res = max(count, res)
        return res<=1