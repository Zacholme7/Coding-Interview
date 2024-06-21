# link: https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
# difficulty: medium
# date solved: june 21, 2024

class Solution:
    def maxSatisfied(self, customers, grumpy, minutes):
        n = len(customers)

        # Calculate initially satisfied customers
        initially_satisfied = sum(customers[i] for i in range(n) if grumpy[i] == 0)

        # Calculate the initial window of additional satisfied customers
        current_window = sum(customers[i] * grumpy[i] for i in range(minutes))
        max_window = current_window

        # Slide the window and update max_window
        for i in range(minutes, n):
            current_window += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes]
            max_window = max(max_window, current_window)

        return initially_satisfied + max_window


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxSatisfied(customers=[1, 0, 1, 2, 1, 1, 7, 5], grumpy=[0, 1, 0, 1, 0, 1, 0, 1], minutes=3))
    print(sol.maxSatisfied(customers=[1], grumpy=[0], minutes=1))
