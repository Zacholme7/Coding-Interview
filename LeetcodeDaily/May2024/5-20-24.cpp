// link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
// difficulty: easy
// date solved: may 20, 2024
#include <vector>
using namespace std;

class Solution {
public:
  void generateSubsets(int currIdx, int currXorTotal, vector<int> &nums,
                       int &xorTotal) {
    // base case
    if (currIdx == nums.size()) {
      xorTotal = xorTotal + currXorTotal;
      return;
    }

    // pick
    generateSubsets(currIdx + 1, currXorTotal ^ nums[currIdx], nums, xorTotal);
    // not pick
    generateSubsets(currIdx + 1, currXorTotal, nums, xorTotal);
  }

  int subsetXORSum(vector<int> &nums) {
    int xorTotal = 0;
    generateSubsets(0, 0, nums, xorTotal);
    return xorTotal;
  }
};
