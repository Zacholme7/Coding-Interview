// link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02
// difficulty: easy
// date solved: may 2, 2024
// writeup: we are always looking for the negation of the current number. the first step is to just add the number to our set. we can
// then look for the negation in the find clause as pos -> neg and neg -> pos (double neg). if we found the opposite, then we want
// to take the new max val so we abs the number

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxK(vector<int> &nums) {
    int maxNum = -1;
    set<int> numSet;

    for (int num: nums) {
      numSet.insert(num);
      if(numSet.find(-num) != numSet.end()) {
        maxNum = max(maxNum, abs(num));
      }
    }
    return maxNum;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> test1{-1, 2, -3, 3};
  vector<int> test2{-1, 10, 6, 7, -7, 1};
  vector<int> test3{-10, 8, 6, 7, -2, -3};
  cout << sol.findMaxK(test1) << endl;
  cout << sol.findMaxK(test2) << endl;
  cout << sol.findMaxK(test3) << endl;
  return 0;
}
