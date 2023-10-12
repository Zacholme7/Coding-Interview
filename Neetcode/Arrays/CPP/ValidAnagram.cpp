// Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy
// Date solved: April 20, 2023
/*
Solution:
This is a simple problem. We have to check if the two strings s and t are anagrams of each other, meaning
that they have the exact same amount of each letters. Initally, we check the lenghts. If they dont have the
same length we obviously know they are not anagrams. If they are the same length, we want to loop through
and add the letters of one to a map and subtract the letters of another from the same map. At the end,
we check to see if any of the results are not zero, meaning that it did not have a corresponding amount
in the order string, meaning they are not anagrams. At the end, you just return the correct logic.
*/


#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // check the lengths
        if(s.length() != t.length()) {
            return false;
        }

        // count the letters
        unordered_map<char, int> cntMap;
        for(int i = 0; i < s.length(); i++) {
            cntMap[s[i]]++;
            cntMap[t[i]]--;
        }

        // check if any non zero elements
        bool hasNonZero =  any_of(cntMap.begin(), cntMap.end(), [](auto const& element){return element.second != 0;});
        return hasNonZero != true;
    }
};

int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << " should be 1" << endl;
    cout << sol.isAnagram("cat", "rat") << " should be 0" << endl;
    return 0;
}