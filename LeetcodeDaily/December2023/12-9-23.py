# link: https://leetcode.com/problems/binary-tree-inorder-traversal/?envType=daily-question&envId=2023-12-09
# Difficulty: Easy
# Date solved: December 9, 2023

class Solution:
    def inorderHelper(self, res, root):
        if root == None:
            return
        self.inorderHelper(res, root.left)
        res.append(root.val)
        self.inorderHelper(res, root.right)

    def inorderTraversal(self, root):
        res = []
        if root == None:
            return res
        self.inorderHelper(res, root)
        return res




