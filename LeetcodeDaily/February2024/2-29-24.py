# link: https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
# difficulty: medium
# date solved: february 29, 2024

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isEvenOddTree(self, root):
        if not root:
            return True

        level = 0
        queue = [root]

        while queue:
            level_length = len(queue)
            prev_value = None

            for i in range(level_length):
                node = queue.pop(0)
                if level % 2 == 0:  # Even level: nodes must have odd values, increasing
                    if node.val % 2 == 0 or (prev_value is not None and prev_value >= node.val):
                        return False
                else:  # Odd level: nodes must have even values, decreasing
                    if node.val % 2 != 0 or (prev_value is not None and prev_value <= node.val):
                        return False
                prev_value = node.val

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1

        return True
