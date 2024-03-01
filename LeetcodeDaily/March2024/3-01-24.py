# link: https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
# difficulty: easy
# date solved: march 1, 2024

class Solution:
    def maximumOddBinaryNumber(self, s):
        numZero = 0
        numOne = -1

        for num in s:
            if num == "0":
                numZero += 1
            else:
                numOne += 1

        return ("1" + numZero * "0" + numOne * "1")[::-1]


if __name__ == "__main__":
    sol = Solution()
    print(sol.maximumOddBinaryNumber("010"))
    print(sol.maximumOddBinaryNumber("0101"))
