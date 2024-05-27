# link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
# difficulty: easy
# date solved: may 27, 2024

class Solution:
    def specialArray(self, nums):
        # loop through all potential specials
        for potentialSpecial in range(0, len(nums) + 1):
            counter = 0 # track number of elements greater
            # go through all the nums
            for num in nums:
                # increament if found number greater
                if potentialSpecial <= num:
                    counter += 1
                # see if this number is special
            if potentialSpecial == counter:
                return potentialSpecial
        return -1



