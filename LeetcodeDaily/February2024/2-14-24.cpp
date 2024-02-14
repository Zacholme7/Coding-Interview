// link:
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14
// difficulty: medium
// date solved: february 24, 2024
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> posNums;
    vector<int> negNums;
    for(int num: nums) {
      if (num > 0) {
        posNums.push_back(num);
      } else {
        negNums.push_back(num);
      }
    }

    vector<int>res;
    for(int i = 0; i < posNums.size(); i++) {
      res.push_back(posNums[i]);
      res.push_back(negNums[i]);
    }

    return res;
  }
};

int main() {}
