// link: https://leetcode.com/problems/palindrome-partitioning/?envType=daily-question&envId=2024-05-22
// difficulty: medium
// date solved: May 22, 20245
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isPalindrome(const string &s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }

  void partitionHelper(int idx, vector<string> &tracker,
                       vector<vector<string>> &res, string &s) {
    if (idx == s.size()) {
      res.push_back(tracker);
      return;
    }

    for (int i = idx; i < s.size(); ++i) {
      if (isPalindrome(s, idx, i)) {
        tracker.push_back(s.substr(idx, i - idx + 1));
        partitionHelper(i + 1, tracker, res, s);
        tracker.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if (s.empty()) {
      return res;
    }
    vector<string> tracker;
    partitionHelper(0, tracker, res, s);
    return res;
  }
};
