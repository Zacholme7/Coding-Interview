// link:
// https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
// difficulty: easy
// date solved: february 20, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int missingNum = (nums.size() * (nums.size() + 1)) / 2;
    for(int num: nums) {
      missingNum = missingNum - num;
    }
    return missingNum;
  }
};
