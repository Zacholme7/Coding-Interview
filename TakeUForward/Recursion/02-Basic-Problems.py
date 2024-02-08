# link: https://www.youtube.com/watch?v=un6PLygfXrA&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=2

class Solution:
    # O(n): recursing n times
    # O(n): (stack space) just the number of recursive calls
    def printName(self, name, n):
        if n == 0:
            return
        print(name)
        self.printName(name, n - 1)

    # O(n): recursing n times
    # O(n): (stack space) just the number of recursive calls
    def printNto1(self, n):
        if n == 0:
            return
        print(n)
        self.printNto1(n - 1)

    # O(n): recursing n times
    # O(n): (stack space) just the number of recursive calls
    def print1toN(self, n):
        if n == 0:
            return
        self.print1toN(n - 1)
        print(n)


if __name__ == "__main__":
    sol = Solution()
    sol.printName("hello", 3)
    sol.printNto1(4)
    sol.print1toN(4)
