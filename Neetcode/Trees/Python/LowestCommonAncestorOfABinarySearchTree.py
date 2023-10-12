# Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
# Difficulty: Medium
# Date solved: Oct 5, 2023
# Solution
# Since it is a binary search tree, we can utlize the property
# that the node to the left will be smaller and the node to the right
# will be bigger. If p and q are less than the root, then the lca must be on the 
# left side so we can move there. If p and q are greater than the root
# then p and q must be on the right side. Otherwise, p and q are inbetween some
# node which would be the lca or one of them are the lca

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root






