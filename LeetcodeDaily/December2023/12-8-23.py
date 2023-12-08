# Link: https://leetcode.com/problems/construct-string-from-binary-tree/?envType=daily-question&envId=2023-12-08
# Difficulty: Easy
# Date Solved: December 8, 2023

class Solution:
    def tree2str(self, root):
        if not root:
            return ""

        left = "({})".format(self.tree2str(root.left)) if (root.left or root.right) else ""
        right = "({})".format(self.tree2str(root.right)) if root.right else ""
        return "{}{}{}".format(root.val, left, right)



