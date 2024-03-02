// link: https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02
// difficulty: easy
// date solved: march 2, 2024
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    int s = 0, e = n - 1;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      if (abs(nums[s]) >= abs(nums[e])) {
        ans[i] = nums[s] * nums[s];
        s++;
      } else {
        ans[i] = nums[e] * nums[e];
        e--;
      }
    }
    return ans;
  }
};
