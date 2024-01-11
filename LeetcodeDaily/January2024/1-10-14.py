# link:https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
# difficulty: medium
# date solved: january 10, 2024

from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def generateNodeGraph(self, root, nodeGraph):
        queue = [root]
        while queue:

            for _ in range(len(queue)):
                currNode = queue.pop(0)

                if currNode.left:
                    nodeGraph[currNode.val].append(currNode.left.val)
                    nodeGraph[currNode.left.val].append(currNode.val)
                    queue.append(currNode.left)
                if currNode.right:
                    nodeGraph[currNode.val].append(currNode.right.val)
                    nodeGraph[currNode.right.val].append(currNode.val)
                    queue.append(currNode.right)

    def bfs(self, nodeGraph, start):
        minutes = 0
        queue = [start]  # Start with the 'start' node
        visited = set([start])  # Initialize 'visited' set with the 'start' node

        while queue:
            qLen = len(queue)
            for _ in range(qLen):
                currVal = queue.pop(0)
                for ele in nodeGraph[currVal]:
                    if ele not in visited:
                        visited.add(ele)
                        queue.append(ele)

            if queue:  # Only increment minutes if there are more nodes to visit
                minutes += 1

        return minutes

    def amountOfTime(self, root, start):
        nodeGraph = defaultdict(list)
        self.generateNodeGraph(root, nodeGraph)
        return self.bfs(nodeGraph, start)
