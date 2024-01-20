# link: https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279
# difficulty: easy
# date solved: january 20, 2024
# Time: O(n)
# Space: O(1)

class Solution:
    def largestElement(self, arr, n):
        largest = arr[0]
        for ele in arr:
            if ele > largest:
                largest = ele

        return largest


if __name__ == "__main__":
    sol = Solution()
    print(sol.largestElement([1, 2, 3, 4, 5], 5))
