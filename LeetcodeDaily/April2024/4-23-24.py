# link: https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23
# difficulty: medium
# date solved: april 23, 2024
# writeup: make a adj list and go a bfs on each of the roots to find the height of each one and then
# figure out which ones are the minimum

from collections import defaultdict, deque


class Solution:
    def getMinHeight(self, root, adjList):
        queue = deque([(root, 0)])  # Initialize queue with root and depth 0
        visited = {root}
        maxHeight = 0

        while queue:
            node, depth = queue.popleft()
            maxHeight = max(maxHeight, depth)
            for neighbor in adjList[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, depth + 1))

        return maxHeight

    def findMinHeightTrees(self, n, edges):
        if n == 1:  # Special case where the graph has only one node
            return [0]

        adjList = defaultdict(list)

        # Build the adjacency list
        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)

        # Compute the minimum height among all possible roots
        minHeight = float('inf')
        minTrees = []

        for root in range(n):
            height = self.getMinHeight(root, adjList)
            if height < minHeight:
                minHeight = height
                minTrees = [root]
            elif height == minHeight:
                minTrees.append(root)

        return minTrees
