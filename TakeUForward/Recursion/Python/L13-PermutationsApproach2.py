# Link: https://leetcode.com/problems/permutations/description/
# Difficulty: Medium
# Date solved: November 3, 2023
#Solution:
#This is definitely a tricky approach but it makes it so that we dont have to store the extraneous array to track what we have and have not see. The idea behid this
#is that we can iterate over the array, but we want to swop the positions to generate the new permutations. We have a constant swap index (idx) that we swap
#with the ith value on each iteration. this will generate us a nwe permuation each time. I have a helper to do the swaping and the base case is when we reach past the 
#last index and we want to add the result at that time which will be a new permutaiton. In the main loop, I swap with the swapPos and the ith positon, then incrase the 
#swap pos to move onto the next element. on the return of the function call, I restore the original array and the ith position is increased so we can swap new elements
#and create a new permutation. 


class Solution:

    def swap(self, first, second, nums):
        tmp = nums[second]
        nums[second] = nums[first]
        nums[first] = tmp

    def permuteHelper(self, idx, nums, res):
        if idx == len(nums):
            res.append(nums.copy())
            return

        for i in range(len(nums)):
            self.swap(idx, i, nums)
            self.permuteHelper(idx + 1, nums, res)
            self.swap(i, idx, nums)

    def permute(self, nums):
        res = []
        self.permuteHelper(0, nums, res)
        return res
