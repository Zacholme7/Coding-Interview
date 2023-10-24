# Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
# Difficulty: Medium
# Date solved: Oct 11, 2023
# Solution
# always keep track of the current good node and just do a bfs

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root):
        if root is None:
            return 0
        queue = [(root, root.val)]
        numGoodNodes = 0
        while queue:
            qLen = len(queue)
            for _ in range(qLen):
                currNode, currMax = queue.pop(0)
                if currNode.val >= currMax:
                    numGoodNodes += 1
                if currNode.left:
                    queue.append((currNode.left, max(currMax, currNode.left.val)))
                if currNode.right:
                    queue.append((currNode.right, max(currMax, currNode.right.val)))
        return numGoodNodes

