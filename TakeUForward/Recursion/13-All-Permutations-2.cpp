// link: https://leetcode.com/problems/permutations/
// difficulty: medium
// date solved: february 11, 2024
#include <vector>
using namespace std;

class Solution {
public:
  void swap(int start, int end, vector<int> &nums) {
    int tmp = nums[start];
    nums[start] = nums[end];
    nums[end] = tmp;
  }

  void helper(vector<int> &nums, vector<vector<int>> &res, int idx) {
    if (idx == nums.size()) {
      res.push_back(nums);
    }

    for (int i = idx; i < nums.size(); i++) {
      swap(idx, i, nums);
      helper(nums, res, idx + 1);
      swap(i, idx, nums);
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    helper(nums, res, 0);
    return res;
  }
};
