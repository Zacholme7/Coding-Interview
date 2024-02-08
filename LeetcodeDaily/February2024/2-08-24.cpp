// link: https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08
// difficulty: medium
// date solved: february 8, 2024
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    // vector for updating the dp array/values
    vector<int> dp(n + 1, INT_MAX);
    // base case
    dp[0] = 0;
    int count = 1;
    while (count * count <= n) {
      int sq = count * count;
      for (int i = sq; i < n + 1; i++) {
        dp[i] = min(dp[i - sq] + 1, dp[i]);
      }
      count++;
    }
    return dp[n];
  }
};

int main() {
  Solution sol;
  cout << sol.numSquares(12) << endl;
  cout << sol.numSquares(13) << endl;
}
