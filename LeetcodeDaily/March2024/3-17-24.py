# link: https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17
# difficulty: medium
# date solved: march 17, 2024

class Solution:
    def insert(self, intervals, newInterval):
        merged = []
        i = 0

        while i < len(intervals) and intervals[i][1] < newInterval[0]:
            merged.append(intervals[i])
            i += 1

        while i < len(intervals) and intervals[i][0] <= newInterval[1]:
            newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]
            i += 1
        merged.append(newInterval)

        while i < len(intervals):
            merged.append(intervals[i])
            i += 1

        return merged
