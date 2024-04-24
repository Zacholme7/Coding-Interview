// link: https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24
// difficulty: easy
// date solved: april 24, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int tribonacci(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    if (n == 2)
      return 1;

    vector<int> seq(n + 1, 0);
    seq[0] = 0;
    seq[1] = 1;
    seq[2] = 1;
    for(int i = 3; i <= n; i++) {
      seq[i] = seq[i-1] + seq[i-2] + seq[i-3];
    }
    return seq[n];
  }
};
