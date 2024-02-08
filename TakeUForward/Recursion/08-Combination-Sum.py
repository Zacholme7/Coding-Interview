# link: https://leetcode.com/problems/combination-sum/description/
# video: https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10
# difficulty: medium
# date solved: february 5, 2024

class Solution:
    def combinationSumHelper(self, candidiates, tracker, res, idx, currSum):
        if idx == len(candidiates):
            if currSum == 0:
                res.append(tracker.copy())
            return

        if candidiates[idx] <= currSum:
            tracker.append(candidiates[idx])
            self.combinationSumHelper(candidiates, tracker, res, idx, currSum - candidiates[idx])
            tracker.pop()
        self.combinationSumHelper(candidiates, tracker, res, idx + 1, currSum)

    def combinationSum(self, candidates, target):
        res = []
        self.combinationSumHelper(candidates, [], res, 0, target)
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.combinationSum([2, 3, 6, 7], 7))
    print(sol.combinationSum([2, 3, 5], 8))
    print(sol.combinationSum([2], 1))
