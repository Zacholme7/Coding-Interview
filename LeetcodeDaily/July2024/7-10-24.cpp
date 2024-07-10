// link:
// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
// difficulty: easy
// date solved: july 10, 2024
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int distance_from_root = 0;
    for (const string &log : logs) {
      if (log == "../") {
        if (distance_from_root > 0) {
          distance_from_root--;
        }
      } else if (log == "./") {
        // No operation needed
      } else {
        distance_from_root++;
      }
    }
    return distance_from_root;
  }
};
