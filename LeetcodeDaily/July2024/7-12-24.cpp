// link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12
// difficulty: medium
// date solved: july 12, 2024
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    // Determine which substring is more valuable
    const char *more = (x > y) ? "ab" : "ba";
    const char *less = (x > y) ? "ba" : "ab";
    int more_points = std::max(x, y);
    int less_points = std::min(x, y);

    return removeSubstrings(s, more, more_points) +
           removeSubstrings(s, less, less_points);
  }

private:
  int removeSubstrings(string &s, const char *sub, int points) {
    int total = 0;
    string result;
    result.reserve(s.length()); // Pre-allocate memory

    for (char c : s) {
      if (!result.empty() && c == sub[1] && result.back() == sub[0]) {
        result.pop_back();
        total += points;
      } else {
        result.push_back(c);
      }
    }

    s = std::move(result); // Efficient swap
    return total;
  }
};
