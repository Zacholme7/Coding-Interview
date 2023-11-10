# Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/?envType=daily-question&envId=2023-11-10
# Difficulty: Medium
# Date solved: November 10, 2023

from collections import defaultdict
class Solution:
    def restoreArray(self, pairs):
        # Create a graph to represent adjacent pairs
        graph = defaultdict(list)
        for u, v in pairs:
            graph[u].append(v)
            graph[v].append(u)

        # Initialize the result list
        res = []

        # Find the starting node with only one neighbor
        for node, neighbors in graph.items():
            if len(neighbors) == 1:
                res = [node, neighbors[0]]
                break

        # Continue building the array until its length matches the number of pairs
        while len(res) < len(pairs) + 1:
            # Get the last two elements in the result array
            last, prev = res[-1], res[-2]

            # Find the candidates for the next element
            candidates = graph[last]

            # Choose the candidate that is not the previous element
            next_element = candidates[0] if candidates[0] != prev else candidates[1]

            # Append the next element to the result array
            res.append(next_element)

        return res