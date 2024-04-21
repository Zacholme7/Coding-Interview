# link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21
# difficulty: easy
# date solved: april 21, 2024

from collections import defaultdict


class Solution:
    def dfs(self, adjList, visited, source, destination):
        if source == destination:
            return True
        visited[source] = True
        for neighbor in adjList[source]:
            if visited[neighbor] is False:
                if self.dfs(adjList, visited, neighbor, destination):
                    return True
        return False

    def validPath(self, n, edges, source, destination):
        # make the adjacency list
        adjList = defaultdict(list)
        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)
        visited = [False] * n
        return self.dfs(adjList, visited, source, destination)
