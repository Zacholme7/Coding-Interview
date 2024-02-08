
class Solution:
    def subsetSum(self, nums):
        res = []

        def subsetSumHelper(idx, currSum):
            nonlocal res

            if idx >= len(nums):
                res.append(currSum)
                return

            # pick
            subsetSumHelper(idx + 1, currSum + nums[idx])
            # not pick
            subsetSumHelper(idx + 1, currSum)

        subsetSumHelper(0, 0)

        return sorted(res)


if __name__ == "__main__":
    sol = Solution()
    print(sol.subsetSum([2, 3]))
    print(sol.subsetSum([5, 2, 1]))
