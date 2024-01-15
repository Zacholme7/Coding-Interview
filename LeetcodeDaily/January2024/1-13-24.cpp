// link:
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
// difficulty: meidum
// date solved: january 13, 2024

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int minSteps(string s, string t) {
    int minSteps = 0;
    unordered_map<int, int> charCnt;

    for (auto i : s) {
      charCnt[i]++;
    }
    for (auto i : t) {
      charCnt[i]--;
    }

    for (auto pair : charCnt) {
      if (pair.second < 0) {
        minSteps += pair.second;
      }
    }

    return abs(minSteps);
  }
};

int main() {
  Solution sol;

  cout << sol.minSteps("bab", "aba") << '\n';
  cout << sol.minSteps("leetcode", "practice") << '\n';
  cout << sol.minSteps("anagram", "mangaar") << '\n';
  return 0;
}
