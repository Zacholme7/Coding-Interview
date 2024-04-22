// link: https://leetcode.com/problems/open-the-lock/?envType=daily-question&envId=2024-04-22
// difficulty: medium
// date solved: april 22, 2024
// writeup: this is a bfs problem. For the starting combo 0000 we get all 8 possible states that we
// can get from the current one and then check if it is our target or not. the bfs will give us the
// shortest path
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    // visited
    unordered_set<string> deadendSet(deadends.begin(), deadends.end());

    // make sure start is not in deadest
    if (deadendSet.count("0000")) {
      return -1;
    }

    queue<pair<string, int>> queue;
    queue.push({"0000", 0});
    unordered_set<string> visited;
    visited.insert("0000");

    while (!queue.empty()) {
      auto current = queue.front(); queue.pop();
      string currentCombination = current.first;
      int moves = current.second;

      // if we are at target
      if (currentCombination == target) {
        return moves;
      }

      // construct new steps
      for (int i = 0; i < 4; i++) {
        for (int delta : {-1, 1}) {
          int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
          string newCombination = currentCombination;
          newCombination[i] = '0' + newDigit;

          // we have not seen this combo yet
          if (visited.find(newCombination) == visited.end() &&
              deadendSet.find(newCombination) == deadendSet.end()) {
            visited.insert(newCombination);
            queue.push({newCombination, moves + 1});
          }
        }
      }
    }

    return -1; // Target is not reachable
  }
};
