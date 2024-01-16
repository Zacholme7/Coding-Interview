// link:
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15
// difficulty: medium
// date solved: january 15, 2024

#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    // player : losses
    unordered_map<int, int> records;

    // results
    vector<int> noLoss;
    vector<int> oneLoss;

    for (auto &match : matches) {
      // get winner and loser
      int winner = match[0];
      int loser = match[1];

      // make sure we have a record for each
      if (records.count(winner) == 0) {
        records[winner] = 0;
      }
      records[loser]++;

    }

    // go through and get all with no losses and one with 1 loss
    for(auto &final: records) {
      // there are no losses
      if (final.second == 0) {
        noLoss.push_back(final.first);
      }

      // there is one loss
      if (final.second == 1) {
        oneLoss.push_back(final.first);
      }
    }

    // get into sorted order
    sort(noLoss.begin(), noLoss.end());
    sort(oneLoss.begin(), oneLoss.end());

    return {noLoss, oneLoss};

  }
};

int main() { return 0; }
