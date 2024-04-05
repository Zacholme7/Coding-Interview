// link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04
// difficulty: easy
// date solved: april 4, 2024
// writeup: whenever we get a new opening, this is a new depth addition so just add it to the counter. Whenver we get a closing,
// this is completing an opening so we decrement our counter since we are going back a depth. just take the max at each iteration
// and return the result at the end
#include <string>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int res = 0;
    int currentDepth = 0;

    // go through all of the characters
    for (auto &c : s) {
      if (c == '(') {
        currentDepth++;
        res = max(res, currentDepth);
      } else if (c == ')') {
        currentDepth--;
      }
    }
    return currentDepth;
  }
};
