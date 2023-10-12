# link: https://leetcode.com/problems/subtree-of-another-tree/description/
# difficulty: easy
# date solved: Oct 2, 2023
# solution
# this is a followup on the sametree problem. We want to find 
# where the two roots match up and run the same tree algorithm to see
# if the subtree is part of the main tree. We have to check for each node,
# because the main tree might be for examples all 1's while the subtree is just one
# node with the value one.


class Solution:
    def isSameTree(self, p, q):
        if p == None and q == None:
            return True
        elif p == None or q == None:
            return False
        elif p.val != q.val:
            return False
        return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)

    def isSubTree(self, root, subRoot):
        if root == None:
            return False
        elif self.isSameTree(root, subRoot):
            return True
        else:
            return self.isSubTree(root,left, subRoot) or self.isSubTree(root.right, subRoot




