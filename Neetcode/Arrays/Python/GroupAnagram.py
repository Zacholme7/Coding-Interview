# Link: https://leetcode.com/problems/group-anagrams/
# Difficulty: Medium
# Date solved: Sept 23, 2023
# Solution
# We want all of the anagrams to be grouped together 
# and the easiest way to tell if a word is an anagram
# is to sort the words and compare them to their alphabetical 
# ordering. If they are the same then that means they are an
# anagram, so we can use this as a key in the dicionary and 
# add any anagram onto a list. At the end we just use some
# list comprehension to turn the values into a list and return
# that 

class Solution:
    def groupAnagrams(self, strs):
        anagramDict = {}
        for word in strs:
            sortedWord = ''.join(sorted(word))
            if sortedWord not in anagramDict:
                anagramDict[sortedWord] = []
            anagramDict[sortedWord].append(word)

        return [x for x in anagramDict.values()]





