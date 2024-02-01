// link: https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31
// difficulty: medium
// date solved: january 31, 2024

#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    std::vector<int> res(temperatures.size(), 0);
    std::vector<std::pair<int, int>> stack; // Pair of temperature and its index

    for (int idx = 0; idx < temperatures.size(); ++idx) {
      int temp = temperatures[idx];
      while (!stack.empty() && temp > stack.back().first) {
        auto [stackT, stackIdx] = stack.back(); // Structured binding (C++17)
        stack.pop_back();
        res[stackIdx] = idx - stackIdx;
      }
      stack.push_back({temp, idx});
    }

    return res;
  }
};
