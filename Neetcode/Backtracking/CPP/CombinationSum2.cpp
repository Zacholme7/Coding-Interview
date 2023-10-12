// Link: https://leetcode.com/problems/combination-sum-ii/description/
// Difficulty: Medium
// Date solved: May 15, 2023
/*
Solution:
*/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void combinationSumHelper(int idx, int currSum, vector<vector<int>> &res, vector<int> &tracker, vector<int> &candidates) {
        if(currSum == 0) {
            res.push_back(tracker);
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }
            if(candidates[i] > currSum) {
                break;
            }
            tracker.push_back(candidates[i]);
            combinationSumHelper(i + 1, currSum - candidates[i], res, tracker, candidates);
            tracker.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tracker;
        combinationSumHelper(0, target, res, tracker, candidates);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> cand1 {10, 1, 2, 7, 6, 1, 5};
    vector<int> cand2 {2, 5, 2, 1, 2};
    cout << sol.combinationSum2(cand1, 8) << endl;
    cout << sol.combinationSum2(cand2, 5) << endl;
    return 0;
}