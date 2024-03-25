# link: https://leetcode.com/problems/find-all-duplicates-in-an-array/?envType=daily-question&envId=2024-03-25
# difficulty: medium
# date solved: march 25, 2024
from collections import defaultdict;

class Solution:
    def findDuplicates(self, nums):
        numDict = defaultdict(int)
        for num in nums:
            numDict[num] += 1

        res = []
        for num, cnt in numDict.items():
            if cnt == 2:
                res.append(num)

        return res




if __name__ == "__main__":
    sol = Solution()
    print(sol.findDuplicates(nums = [4,3,2,7,8,2,3,1]))
    print(sol.findDuplicates(nums = [1,1,2]))
    print(sol.findDuplicates(nums = []))


