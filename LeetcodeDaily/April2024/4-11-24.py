# link: https://leetcode.com/problems/remove-k-digits/?envType=daily-question&envId=2024-04-11
# difficulty: medium
# date solved: april 11, 2024
# writeup: greedy stack based approach. for each digit if it is smaller than the one of the top 
# of the stack we want to remove the top and decrement k, then append the digit onto the stack.
# at the end if we still have elements on the stack take the reminaing k from the top and make
# them into one string

class Solution:
    def removeKdigits(self, num, k):
        stack = []

        for digit in num:
            while stack and k > 0 and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)

        stack = stack[:-k] if k > 0 else stack
        result = "".join(stack).lstrip("0")
        return result if result else "0"


if __name__ == "__main__":
    sol = Solution()
    print(sol.removeKdigits("1432219", 3))
    print(sol.removeKdigits("10200", 1))
    print(sol.removeKdigits("10", 2))
