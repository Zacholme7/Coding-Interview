# link: https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
# difficulty: easy
# date solved: march 9, 2024

class Solution:
    def getCommon(self, nums1, nums2):
        num1Set = set(nums1)
        for num in nums2:
            if num in num1Set:
                return num
        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.getCommon(nums1=[1, 2, 3], nums2=[2, 4]))
    print(sol.getCommon(nums1=[1, 2, 3, 6], nums2=[2, 3, 4, 5]))
