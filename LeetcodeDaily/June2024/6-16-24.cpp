// link: https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17
// difficulty: medium
// date solved: june 16, 2024

class Solution {
public:
  bool judgeSquareSum(int c) {
    for (int divisor = 2; divisor * divisor <= c; divisor++) {
      if (c % divisor == 0) {
        int exponentCount = 0;
        while (c % divisor == 0) {
          exponentCount++;
          c /= divisor;
        }
        if (divisor % 4 == 3 && exponentCount % 2 != 0) {
          return false;
        }
      }
    }
    return c % 4 != 3;
  }
};
