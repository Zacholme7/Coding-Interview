# link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01
# difficulty: medium
# date solved: February 1, 2024

class Solution:
    def divideArray(self, nums, k):
        nums.sort()
        res = []

        for i in range(0, len(nums), 3):
            if nums[i + 2] - nums[i] > k:
                return []
            res.append(nums[i:i + 3])
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.divideArray(nums=[1, 3, 4, 8, 7, 9, 3, 5, 1], k=2))
    print(sol.divideArray(nums=[1, 3, 3, 2, 7, 3], k=3))
