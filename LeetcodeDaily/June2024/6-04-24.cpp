// link: https://leetcode.com/problems/longest-palindrome/?envType=daily-question&envId=2024-06-04
// difficulty: easy
// date solved: june 4, 2024
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> charMap;
    // count all of the characters
    for (auto ch : s) {

      // if we have not seen this cahracter add it
      if (charMap.find(ch) == charMap.end()) {
        charMap[ch] = 0;
      }
      charMap[ch]++;
    }

    int longestPalindrome = 0;
    bool foundOdd = false;

    for (auto &pair : charMap) {
      if (pair.second % 2 != 0) {
        // if we have not added an odd
        if (foundOdd == false) {
          foundOdd = true;
          longestPalindrome = longestPalindrome + pair.second;
        } else {
          longestPalindrome = longestPalindrome + pair.second - 1;
        }
      } else {
        // we have an even number
        longestPalindrome = longestPalindrome + pair.second;
      }
    }

    return longestPalindrome;
  }
};
