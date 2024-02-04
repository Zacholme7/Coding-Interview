// link:
// https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04
// difficulty: hard
// date solved: february 4, 2024
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> map(128, 0);
    for (auto c : t)
      map[c]++;
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size()) {
      if (map[s[end++]]-- > 0)
        counter--;           // in t
      while (counter == 0) { // valid
        if (end - begin < d)
          d = end - (head = begin);
        if (map[s[begin++]]++ == 0)
          counter++; // make it invalid
      }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
  }
};
