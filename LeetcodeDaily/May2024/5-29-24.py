# link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2024-05-29
# difficulty: medium
# date solved: may 29, 2024

class Solution:
    def numSteps(self, s):
        res = 0
        carry = 0

        for i in reversed(range(1, len(s))):
            digit = (int(s[i]) + carry) % 2
            if digit == 0:
                res += 1
            elif digit == 1:
                carry = 1
                res += 2
        return res + carry


if __name__ == "__main__":
    sol = Solution()
    print(sol.numSteps("1101"))
