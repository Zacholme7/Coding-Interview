// link:
// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02
// difficulty: medium
// date solved: february 2, 2024
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
  vector<int> sequentialDigits(int l, int h) {
    queue<int> q;
    for (int i = 1; i <= 9; i++) {
      q.push(i);
    }
    vector<int> ret;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      if (f <= h && f >= l) {
        ret.push_back(f);
      }
      if (f > h)
        break;
      int num = f % 10;
      if (num < 9) {
        q.push(f * 10 + (num + 1));
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  return 0;
}
