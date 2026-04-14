"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        # given the suggested time complexity, some sort of binary tree
        # would make sense as a solution
        # Question: is the array sorted? 
        # brute force: check every pair of intervals and return false if any overlap is found
        intervals.sort(key=lambda x: x.start)
        for i in range(len(intervals)-1):
            if intervals[i].end > intervals[i+1].start:
                return False
        return True