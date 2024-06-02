// link: https://leetcode.com/problems/reverse-string/?envType=daily-question&envId=2024-06-02
// difficulty: easy
// date solved: june 2, 2024
#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (int left = 0; left < s.size() / 2; left++) {
      int right = s.size() - left - 1;
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
    }
  }
};
