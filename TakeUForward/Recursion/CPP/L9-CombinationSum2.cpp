// Link: https://leetcode.com/problems/combination-sum-ii/description/
// Difficulty: Medium
// Date solved: May 15, 2023
/*
Solution:
This problem can be solved by the same process as combination sum with a very slight modification but this way is more simple. 
We want to find all combinations without repetition and that are distrinct. our base case is going to be when currSum is 0 and when it 
is we can add that to our resulting array since we know it will be distinct and that all elements after are greater. So we loop though all numbers
to the left in the sorted canaidates. For each one, we want to go pick it and go down each possible path. The two exceptions being if we have numbers 
that are the same in the row, we dont want to start off with it again, so the first line of logic will skip repeating numbers. The second line of logic is
a shortcut to deal with a path we dont want to go down, since the array is sorted, if the current elemetn is greater than the target we know that we arent going 
to be able to find any solutions so we can just break out of the current loop as we dont want to explore it more. This pattern alongside the last one are two very important
recursive patterns. 
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
            return;
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