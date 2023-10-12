# Link: https://leetcode.com/problems/diameter-of-binary-tree/
# Difficulty: Easy
# Date solved: Oct 1, 2023
# Solution
# this is another twist on the max depth, we want
# to maintain a tracker that will keep track of the 
# current diameter. Each time we want to check if we have a new
# max between the left and the right and the current max. We have to
# use a nested function since we want to edit the max and this can allow us to 
# prevent a copy value

class TreeNode
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxDepth = 0

        def helper(node):
            if node == None:
                return 0
            left = helper(node.left)
            right = helper(node.right)
            nonlocal maxDepth
            maxDepth = max(maxDepth, right + left)
            return max(left, right) + 1
        helper(root)
        return maxDepth
