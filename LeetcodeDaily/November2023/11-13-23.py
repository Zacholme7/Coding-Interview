# link: https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2023-11-13
# difficulty: Medium
# date solved: November 13, 202

class Solution:
    def sortVowels(self, s):
        vw = sorted([c for c in s if c.lower() in 'aeiou'], reverse=True)
        return ''.join([vw.pop() if c.lower() in 'aeiou' else c for c in s])   