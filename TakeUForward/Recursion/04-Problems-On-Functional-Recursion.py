# link: https://www.youtube.com/watch?v=twuC1F6gLI8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=4

class Solution:
    def reverseArrayHelper1(self, arr, left, right):
        if left >= right:
            return
        tmp = arr[left]
        arr[left] = arr[right]
        arr[right] = tmp
        self.reverseArrayHelper(arr, left + 1, right - 1)

    def reverseArrayHelper2(self, arr, i):
        if i > len(arr) // 2:
            return
        tmp = arr[i]
        arr[i] = arr[len(arr) - i - 1]
        arr[len(arr) - i - 1] = tmp
        self.reverseArrayHelper2(arr, i + 1)

    def reverseArray(self, arr):
        self.reverseArrayHelper(arr, 0, len(arr) - 1)
        return arr
