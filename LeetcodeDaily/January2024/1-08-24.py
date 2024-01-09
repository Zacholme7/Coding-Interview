# link: https://leetcode.com/problems/range-sum-of-bst/
# difficulty: easy
# date solved: january 8, 2024

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSumBST(self, root, low, high):
        sum = 0

        def travHelper(node):
            nonlocal sum
            if node == None:
                return

            travHelper(node.left)
            if low <= node.val and node.val <= high:
                sum += node.val
            travHelper(node.right)

        travHelper(root)
        return sum



