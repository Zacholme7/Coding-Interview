# Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
# Difficulty: Medium
# Date solved: Nov 5, 2023
# Solution

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorder(self, root, res):
        if root == None:
            return None
        self.inorder(root.left)
        res.append(root.val)
        self.inorder(root.right)

    def kthSmallestElement(self, root, k):
        inorder = []
        self.inorder(root, inorder)
        return inorder[k - 1]


    
