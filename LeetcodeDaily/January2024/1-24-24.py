# link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
# difficulty: medium
# date solved: january 24, 2024

class Solution:

    def checkPalindrome(self, numCnt):
        haveSeenOdd = False
        for cnt in numCnt:
            if cnt != 0 and cnt % 2 != 0:
                if haveSeenOdd:
                    return False
                else:
                    haveSeenOdd = True

        return True

    def dfs(self, node, numCnt):
        if node is None:
            return 0

        numCnt[node.val] += 1

        numPalindromes = 0

        if not node.left and not node.right:
            if self.checkPalindrome(numCnt):
                numPalindromes += 1

        numPalindromes += self.dfs(node.left, numCnt)
        numPalindromes += self.dfs(node.right, numCnt)

        numCnt[node.val] -= 1

        return numPalindromes

    def pseudoPalindromicPaths(self, root) -> int:
        numCnt = [0] * 10
        return self.dfs(root, numCnt)
