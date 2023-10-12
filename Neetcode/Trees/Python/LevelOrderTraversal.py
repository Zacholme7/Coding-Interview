# Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
# Difficulty: Medium
# Date solved: Oct 3, 2023
# Solution
# simple level order traverasl. Have a queue and for each 
# level you want to loop through the entire queue. Pop each 
# node off of the front and then add its value to a current level
# array, add its children to the queue, and then move onto the next node
# when the level is complete add the level array to the resulting array

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root):
        if root == None:
            return []
        queue = [root]
        res = []

        while queue:
            currLvl = []
            for _ in range(len(queue)):
                currNode = queue.pop(0)
                currLvl.append(currNode.val)

                if currNode.left:
                    queue.append(currNode.left)

                if currNode.right:
                    queue.append(currNode.right)

            res.append(currLvl)
        return res




