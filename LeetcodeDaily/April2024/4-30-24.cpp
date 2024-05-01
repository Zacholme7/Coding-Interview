// link: https://leetcode.com/problems/number-of-wonderful-substrings/?envType=daily-question&envId=2024-04-30
// difficulty: medium
// date solved: april 30, 2024
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  long long wonderfulSubstrings(string word) {
    unordered_map<int, int> count;
    count[0] = 1;
    long long result = 0;
    int bitmask = 0;

    for (char ch : word) {
      int charIndex = ch - 'a';
      bitmask ^= 1 << charIndex;
      result += count[bitmask];
      for (int i = 0; i < 10; i++) {
        result += count[bitmask ^ (1 << i)];
      }
      count[bitmask]++;
    }

    return result;
  }
};
