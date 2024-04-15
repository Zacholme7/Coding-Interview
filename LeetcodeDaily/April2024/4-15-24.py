# link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15
# difficulty: medium
# date solved: April 15, 2024

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumNumbers(self, root):
        self.res = 0  # Use an instance variable to keep track of the sum of numbers

        def helper(node, numStr):
            # Base case: if the node is None, do nothing
            if node is None:
                return

            # Append current node's value to the numStr
            currentStr = numStr + str(node.val)

            # If we are at a leaf node, convert currentStr to an integer and add to res
            if node.left is None and node.right is None:
                self.res += int(currentStr)
                return

            # Recursive calls for left and right children
            helper(node.left, currentStr)
            helper(node.right, currentStr)

        # Initial call to helper with an empty string for numStr
        helper(root, "")
        return self.res
