# link: https://leetcode.com/problems/length-of-last-word/?envType=daily-question&envId=2024-04-01
# difficulty: easy
# date solved: April 1, 2024
# writeup: just use the split function to split all of the words up and then return the last word

class Solution:
    def lengthOfLastWord(self, s):
        words = s.split()
        return len(words[-1])


if __name__ == "__main__":
    sol = Solution()
    print(sol.lengthOfLastWord(s="Hello World"))
    print(sol.lengthOfLastWord(s="   fly me   to   the moon  "))
    print(sol.lengthOfLastWord(s="luffy is still joyboy"))
