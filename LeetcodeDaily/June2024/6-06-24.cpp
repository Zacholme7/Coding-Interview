// link: https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06
// difficulty: medium
// date solved: june 6, 2024

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    // If the total number of cards is not a multiple of groupSize, it's
    // impossible to form the required groups
    if (hand.size() % groupSize != 0) {
      return false;
    }

    // Create a map to count the occurrences of each card
    map<int, int> numCounts;
    for (int num : hand) {
      numCounts[num]++;
    }

    // Iterate through the map and try to form the groups
    for (auto &entry : numCounts) {
      int currentNum = entry.first;
      int count = entry.second;

      // If there are cards to be grouped from this point
      if (count > 0) {
        // Check for the next groupSize-1 consecutive numbers
        for (int i = 1; i < groupSize; ++i) {
          numCounts[currentNum + i] -= count;
          // If there are not enough cards to form a group, return false
          if (numCounts[currentNum + i] < 0) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
