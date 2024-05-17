# link: https://leetcode.com/problems/delete-leaves-with-a-given-value/?envType=daily-question&envId=2024-05-17
# difficulty: medium
# date solved: may 15, 2024

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isLeaf(self, node):
        return node.left is None and node.right is None

    def removeLeafNodes(self, root, target):
        if root is None:
            return

        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)

        if self.isLeaf(root) and root.val == target:
            return None

        return root
