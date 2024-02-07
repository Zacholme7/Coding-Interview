// link: https://leetcode.com/problems/combination-sum-ii/
// difficulty: medium
// date solved: february 6, 2024

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  void helper(vector<int> &candidates, vector<vector<int>> &res,
              vector<int> &tracker, int target, int idx) {
    if (target == 0) {
      res.push_back(tracker);
      return;
    }
    if (target < 0 || idx >= candidates.size()) {
      return;
    }

    for (int i = idx; i < candidates.size(); i++) {
      // Skip duplicates
      if (i > idx && candidates[i] == candidates[i - 1])
        continue;

      // Include the current candidate
      tracker.push_back(candidates[i]);
      helper(candidates, res, tracker, target - candidates[i], i + 1);
      tracker.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tracker;
    helper(candidates, res, tracker, target, 0);
    return res;
  }
};
