// link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28
// difficulty: medium
// date solved: may 28, 2024
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int left = 0;
    int maxLen = 0;
    int currentCost = 0;

    for (int right = 0; right < s.size(); right++) {
      // calculate the cost of this char
      int charCost = abs(int(s[right]) - int(t[right]));
      currentCost += charCost;

      // if we cannot accommodate it, slide the left pointer
      while (currentCost > maxCost) {
        int leftCharCost = abs(int(s[left]) - int(t[left]));
        currentCost -= leftCharCost;
        left++;
      }

      // update the length
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};
