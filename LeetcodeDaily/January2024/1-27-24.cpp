// link:
// https://leetcode.com/problems/k-inverse-pairs-array/?envType=daily-question&envId=2024-01-27
// difficulty: hard
// date solved: january 27, 2024
// yeaaa i did not solve this one...
class Solution {
public:
  int kInversePairs(int n, int k) {
    int dp[2][1001] = {1};
    for (int N = 1; N <= n; ++N)
      for (int K = 0; K <= k; ++K) {
        dp[N % 2][K] =
            (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
        if (K >= N)
          dp[N % 2][K] =
              (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
      }
    return dp[n % 2][k];
  }
};

int main() {
  return 0;
}
