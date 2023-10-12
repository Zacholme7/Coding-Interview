# Link: https://leetcode.com/problems/binary-tree-right-side-view/
# Difficulty: Medium
# Date solved: Oct 3, 2023
# Solution
# this is just a twist on a level order traversal
# we want to do a level order, but we just want to take
# only the right side which means we can adjust our traversal
# to make sure that the rightmost nodes are at the front
# of the queue for each new level iteration and just add that
# node into a resulting array

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root):
        if root == None:
            return []
        queue = [root]
        res = []
        while queue:
            firstNode = False
            for _ in range(len(queue)):
                currNode = queue.pop(0)
                if firstNode == False:
                    res.append(currNode.val)
                    firstNode = True

                if currNode.right:
                    queue.append(currNode.right)

                if currNode.left:
                    queue.append(currNode.left)

        return res


