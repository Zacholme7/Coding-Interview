# Link: https://leetcode.com/problems/validate-binary-search-tree/
# Difficulty: Medium
# Date Solved: November 4th, 2023
# Solution
# this solution requires going through the entire tree. We know that an inorder traveresal
# will get all of the node values in the correct order. So we can just do that and interate over the
# list. A proper binary search tree will have all of these values in increasing order, so we can just check this
# in a loop

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

	def inOrderTraversal(self, root, inOrderList):
		if root == None:
			return
		self.inOrderTraversal(root.left, inOrderList)
		inOrderList.append(root.val)
		self.inOrderTraversal(root.right, inOrderList)

	def isValidBST(self, root):
		inOrderList = []
		self.inOrderTraversal(root, inOrderList)
		for i in range(1, len(inOrderList)):
			if inOrderList[i -1] >= inOrderList[i]:
				return False
		return True




