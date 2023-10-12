# Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
# Difficulty: Medium
# Date solved: August 29, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root):
        if not root:
            return []
        q = [root]
        res = []
        while q:
            currLvl = []
            for _ in range(len(q)):
                currNode = q.pop(0)
                currLvl.append(currNode.val)

                if currNode.left:
                    q.append(currNode.left)
                if currNode.right:
                    q.append(currNode.right)
            res.append(currLvl)
        return res
            



