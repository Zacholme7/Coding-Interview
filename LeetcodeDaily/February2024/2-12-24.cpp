// link:
// https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
// difficulty: easy
// date solved: february 12, 2024
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> numCnt;
    for(int num: nums) {
      numCnt[num]++;
    }

    for(auto pair: numCnt) {
      if (pair.second > nums.size() / 2) {
        return pair.first;
      }
    }

    return -1;
  }
};

