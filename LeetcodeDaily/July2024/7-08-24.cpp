// link:
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08
// difficulty: medium
// date solved: july 8, 2024
#include <queue>
using namespace std;

class Solution {
public:
  int findTheWinner(int n, int k) {
    queue<int> res;
    for (int i = 0; i < n; i++) {
      res.push(i + 1);
    }

    while (res.size() > 1) {
      for (int i = 0; i < k - 1; i++) {
        // move from the front to the back
        int num = res.front();
        res.pop();
        res.push(num);
      }

      // get rid of the front element
      res.pop();
    }
    return res.front();
  }
};
