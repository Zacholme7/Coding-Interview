# link: https://leetcode.com/problems/same-tree/
# difficulty: easy
# date solved: oct 2, 2023
# solution
# this is just a traversal and at each time we want to check
# that the trees are the same. first we look if they are both
# none which means we are at the bottom and they are the same tree,
# and return true in this case. the next case we check if either p 
# or q are none, this means that the first case failed so either one is none
# or they both are not none, return false if this case passes. last, we know 
# they are both not none so we check the values to see if they are the same,
# then recurse on the left and the rigth subtrees

class treenode:
    def __init__(self, val=0, left=none, right=none):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q):
        if p == None and q == None:
            return True
        elif p == None or q == None:
            return False
        elif p.val != q.val:
            return False
        return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)


