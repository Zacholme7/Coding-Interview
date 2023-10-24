# Video: https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7
# Date: May 11, 2023
# This video just went off some common subsequence modifications: 
# print all answers, 
# print answer once, 
# print number of answers
# Time Complexity: 2 ^ n

class Solution:
    # print the subsequences whose sum is of k
    def print_sub_equal_k(self, idx, ds, curr_sum, sum, nums, size):
        # the common pattern, just keep track of a current sum alongsidek 
        if idx == size:
            if curr_sum == sum:
                print(ds)
            return

        ds.append(nums[idx])
        curr_sum += nums[idx]
        self.print_sub_equal_k(idx + 1, ds, curr_sum, sum, nums, size)
        ds.pop(-1)
        curr_sum -= nums[idx]
        self.print_sub_equal_k(idx + 1, ds, curr_sum, sum, nums, size)

    # print the subsequence whose sum is k only once
    def print_sub_equal_k_once(self, idx, ds, curr_sum, sum, nums, size):
        # the common pattern, just keep track of a current sum alongsidek 
        if idx == size:
            if curr_sum == sum:
                print(ds)
                return True
            return False

        ds.append(nums[idx])
        curr_sum += nums[idx]
        if self.print_sub_equal_k(idx + 1, ds, curr_sum, sum, nums, size):
            return True
        ds.pop(-1)
        curr_sum -= nums[idx]
        if self.print_sub_equal_k(idx + 1, ds, curr_sum, sum, nums, size):
            return True

        return False

    # print the number of subsequences whose sum is equal to k
    def print_sub_equal_k_cnt(self, idx, curr_sum, sum, nums, size):
        if idx == size:
            if curr_sum == sum:
                return 1
            return 0
        
        curr_sum += nums[idx]
        cntAddTotal = self.print_sub_equal_k_cnt(self, idx + 1, curr_sum, sum, nums, size)
        curr_sum -= nums[idx]
        cntNotAddTotal = self.print_sub_equal_k_cnt(self, idx + 1, curr_sum, sum, nums, size)
        return cntAddTotal + cntNotAddTotal

    




    






