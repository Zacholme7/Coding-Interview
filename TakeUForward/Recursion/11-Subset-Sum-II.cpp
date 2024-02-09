// link: https://leetcode.com/problems/subsets-ii/description/
// difficulty: medium
// date solved: February 9, 2024
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  void helper(vector<vector<int>> &res, vector<int> &tracker, vector<int> &nums,
              int idx) {
    res.push_back(tracker);

    for (int i = idx; i < nums.size(); i++) {
      if (i > idx && nums[i - 1] == nums[i]) {
        continue;
      }
      tracker.push_back(nums[i]);
      helper(res, tracker, nums, i + 1);
      tracker.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> tracker;
    sort(nums.begin(), nums.end());
    helper(res, tracker, nums, 0);
    return res;
  }
};
