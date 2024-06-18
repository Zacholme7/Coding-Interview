// link: https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
// difficulty: medium
// date solved: june 18, 2024
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    int n = difficulty.size();
    vector<pair<int, int>> jobs(n);

    // pair difficulty and profit together
    for (int i = 0; i < n; i++) {
      jobs[i] = {difficulty[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    // maxprofit, index for jobs, track best profit
    int maxProfit = 0, i = 0, best = 0;

    for (int w : worker) {
      // while we have not reached out of length and the difficulty is less than
      // the workers difficutly
      while (i < n && jobs[i].first <= w) {
        best = max(best, jobs[i].second);
        i++;
      }
      maxProfit += best;
    }
    return maxProfit;
  }
};
