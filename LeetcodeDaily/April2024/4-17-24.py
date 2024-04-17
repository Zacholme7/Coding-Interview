# link: https://leetcode.com/problems/smallest-string-starting-from-leaf/?envType=daily-question&envId=2024-04-17
# difficulty: medium
# date solve: April 4, 2024
# writeup: pretty simple problem. I just kept a mapping from a node value to its letter. As I recurse I add the letter
# onto a string that we are trackign. If we reach a leaf node, we check if it a new smallest string and if it is 
# we update the current smallest string

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root, currStr, letterMp):
        if root is None:
            return

        # Prepend the current character to build the string from leaf to root
        currStr = letterMp[root.val] + currStr

        # If it's a leaf node, check if it's the lexicographically smallest string
        if root.left is None and root.right is None:
            if self.smallestStr == "" or currStr < self.smallestStr:
                self.smallestStr = currStr
            return

        # Recurse on left and right children
        self.helper(root.left, currStr, letterMp)
        self.helper(root.right, currStr, letterMp)

    def smallestFromLeaf(self, root):
        self.smallestStr = ""
        letters = "abcdefghijklmnopqrstuvwxyz"
        letterMp = {val: letter for val, letter in enumerate(letters)}

        self.helper(root, "", letterMp)
        return self.smallestStr
