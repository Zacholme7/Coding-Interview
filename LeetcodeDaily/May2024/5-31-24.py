# link: https://leetcode.com/problems/single-number-iii/?envType=daily-question&envId=2024-05-31
# difficulty: medium
# date solved: may 31, 2024

class Solution:
    def singleNumber(self, nums):
        xor = 0
        for n in nums:
            xor ^= n

        diff_bit = 1

        while not (xor & diff_bit):
            diff_bit = diff_bit << 1

        a, b = 0, 0

        for n in nums:
            if diff_bit & n:
                a = a ^ n
            else:
                b = b ^ n
        return [a, b]
