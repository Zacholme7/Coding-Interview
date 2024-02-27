# link: https://leetcode.com/problems/diameter-of-binary-tree/?envType=daily-question&envId=2024-02-27
# difficulty: easy
# date solved: february 27, 2024

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root):
        res = 0

        def helper(node):
            nonlocal res
            if node is None:
                return 0
            leftPath = helper(node.left)
            rightPath = helper(node.right)
            res = max(res, leftPath + rightPath)
            return max(leftPath, rightPath) + 1

        helper(root)
        return res
