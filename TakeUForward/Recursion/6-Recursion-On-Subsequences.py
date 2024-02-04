# link: https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
# Time: O(2 ** N)
# Space: O(N)

class Solution:
    def printAllSubsequences(self, arr, idx=0, res=[]):
        if idx == len(arr):
            print(res)
            return

        # take
        res.append(arr[idx])
        self.printAllSubsequences(arr, idx + 1, res)

        # not take
        res.pop()
        self.printAllSubsequences(arr, idx + 1, res)


if __name__ == "__main__":
    sol = Solution()
    sol.printAllSubsequences([1, 2, 3])
