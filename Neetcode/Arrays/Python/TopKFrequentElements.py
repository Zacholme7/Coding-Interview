# Link: https://leetcode.com/problems/top-k-frequent-elements/description/
# Difficulty: Medium
# Date solved: Sept 24, 2023
# Solution
# this is a pretty easy problem, we just want to return a list
# of the elements which appear the top k most frequent times.
# I just use a default dict to track the number of times each 
# element occurs in the list. We can then sort this by the value
# since that says how many time each occurs and then we can just
# return the top k keys which represents the most elements

from collections import defaultdict
class Solution:
    def topKFrequent(self, nums, k):
        res = []
        topFreq = defaultdict(int)
        for num in nums:
            topFreq[num] += 1

        topFreq = dict(sorted(topFreq.items(), key = lambda item: item[1], reverse=True))
        return list(topFreq.keys())[:k]










