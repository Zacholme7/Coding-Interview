// link:
// https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25
// difficulty: medium
// date solved: january 25, 2024

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
  }
};

int main() { 
  Solution sol;
  cout << sol.longestCommonSubsequence("abcde", "ace") << '\n';
  cout << sol.longestCommonSubsequence("abc", "abc") << '\n';
  cout << sol.longestCommonSubsequence("abc", "def") << '\n';
  return 0; 
}

