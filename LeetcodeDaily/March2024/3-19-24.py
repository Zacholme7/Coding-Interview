# link: https://leetcode.com/problems/task-scheduler/?envType=daily-question&envId=2024-03-19
# difficulty: medium
# date solved: march 19, 2024

class Solution:
    def leastInterval(self, tasks, n):
        freq = [0] * 26  # frequency array

        # count the frequency
        for task in tasks:
            freq[ord(task) - ord('A')] += 1
        freq.sort()
        chunk = freq[25] - 1
        idle = chunk * n

        for i in range(24, -1, -1):
            idle -= min(chunk, freq[i])

        return len(tasks) + idle if idle >= 0 else len(tasks)


if __name__ == "__main__":
    sol = Solution()
    print(sol.leastInterval(tasks=["A", "A", "A", "B", "B", "B"], n=2))
    print(sol.leastInterval(tasks=["A", "C", "A", "B", "D", "B"], n=1))
    print(sol.leastInterval(tasks=["A", "A", "A", "B", "B", "B"], n=3))
