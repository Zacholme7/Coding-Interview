// link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14
// difficulty: medium
// date solved: june 14, 2024
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int res = 0, need = 0;
    for (int num : nums) {
      res += max(need - num, 0);
      need = max(num, need) + 1;
    }
    return res;
  }
};
