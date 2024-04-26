// link:https://leetcode.com/problems/minimum-falling-path-sum-ii/?envType=daily-question&envId=2024-04-26
// difficulty: hard
// date solved: april 24, 2024
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &grid) {
    int n = grid.size(), res = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; ++j) {
      dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int temp = INT_MAX;

        for (int k = 0; k < n; ++k) {
          if (k != j) {
            temp = min(temp, grid[i][j] + dp[i - 1][k]);
          }

          dp[i][j] = temp;
        }
      }
    }

    for (int j = 0; j < n; ++j) {
      res = min(res, dp[n - 1][j]);
    }

    return res;
  }
};
