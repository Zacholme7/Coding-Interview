// Link: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium
// Date solved: May 12, 2023
/*
Solution:
This is a short solution code wise but it is a bit difficult to understand how to put it into code the first time. We know that we want to sum to target and we can picl
each element an unlimited number of times. So first off our base case is when the index is the length of the candidates like most recursive problems of this time. In this base
case, if we have a current sum of zero that means that are have found a solution and need to track it in our result. After that, for the index we are at, we want to check 
if the value at that index if less than or equal to the current Sum, if it is, that means we want to pick it up an explore further if we can get a solution with it. Since we
can repeat elements, we then recursively call the function with the same index but take away the current value to the currentSum and at the value of our tracker array. After returing,
we want to remove this value. If the current value is greater than the current sum, that means that we cannot explore the current path anymore and we want to move to the next index
with the currSum to see if there is something else that can be explored.
*/

#include <vector>
#include <iostream>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void combinationSumHelper(int idx, int currSum, vector<vector<int>>& res, vector<int> &tracker, vector<int> &candidates) {
        if(idx == candidates.size()) {
            if(currSum == 0) {
                res.push_back(tracker);
            }
            return;
        }
        if(candidates[idx] <= currSum) {
            tracker.push_back(candidates[idx]);
            combinationSumHelper(idx, currSum - candidates[idx], res, tracker, candidates);
            tracker.pop_back();
        }

        combinationSumHelper(idx + 1, currSum, res, tracker, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tracker;
        combinationSumHelper(0, target, res, tracker, candidates);
        return res;
    }
};


int main() {
    Solution sol;

    return 0;
}