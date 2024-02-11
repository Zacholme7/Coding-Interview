# link: https://leetcode.com/problems/permutations/description/
# difficulty: medium
# date solved: february 10, 2024

class Solution:
    def helper(self, tracker, picked, nums, res):
        if len(tracker) == len(nums):
            res.append(tracker.copy())
            return

        for i in range(len(nums)):
            if picked[i] is True:
                continue

            picked[i] = True
            tracker.append(nums[i])
            self.helper(tracker, picked, nums, res)
            tracker.pop(-1)
            picked[i] = False

    def permute(self, nums):
        res = []
        visited = [False] * len(nums)
        self.helper([], visited, nums, res)
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.permute([1, 2, 3]))
    print(sol.permute([0, 1]))
    print(sol.permute([1]))
