// link: https://www.youtube.com/watch?v=69ZCDFy-OUo&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=3
#include <iostream>

class Solution{
public:
  // parameterised recursion
  void paramSumOfNums(int i, int sum) {
    if (i < 1) {
      std::cout << sum << std::endl;
      return;
    }
    paramSumOfNums(i - 1, sum + i);
  }

  // functional recursion
  int functionalSumOfNums(int i) {
    if (i == 0) {
      return i;
    }
    return i + functionalSumOfNums(i - 1);
  }
};


int main() {
  Solution sol;
  sol.paramSumOfNums(3, 0);
  std::cout << sol.functionalSumOfNums(3) << std::endl;
}

