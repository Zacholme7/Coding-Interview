// link: https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14
// difficulty: medium
// date solved: march 14, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int left1 = 0, left2 = 0, sum1 = 0, sum2 = 0;
    int res = 0;

    for (int right = 0; right < nums.size(); ++right) {
      // Expand the right boundary of our window
      sum1 += nums[right];
      sum2 += nums[right];

      while (left1 <= right && sum1 > goal) {
        sum1 -= nums[left1++];
      }

      while (left2 <= right && sum2 >= goal) {
        sum2 -= nums[left2++];
      }

      res += left2 - left1;
    }

    return res;
  }
};
