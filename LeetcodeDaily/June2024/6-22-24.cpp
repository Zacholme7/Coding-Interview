// link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
// difficulty: medium
// date solved: june 22, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;
    int ans = 0, t = 0;
    for (int v : nums) {
      t += v & 1;
      if (t - k >= 0) {
        ans += cnt[t - k];
      }
      cnt[t]++;
    }
    return ans;
  }
};
