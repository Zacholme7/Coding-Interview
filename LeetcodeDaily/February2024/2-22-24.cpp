// link:
// https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
// difficulty: easy
// date solved: february 22, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> trusted(n + 1);
    for (int i = 0; i < trust.size(); i++) {
      trusted[trust[i][0]]--;
      trusted[trust[i][1]]++;
    }

    for (int i = 1; i < n + 1; i++) {
      if (trusted[i] == n - 1)
        return i;
    }
    return -1;
  }
};
