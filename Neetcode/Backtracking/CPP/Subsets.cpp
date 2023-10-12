// Link: https://leetcode.com/problems/subsets/
// Difficulty: Medium
// Date solved: May 16, 2023
/*
Solution:
One of the most basic recursion problems. All the elemtns are unique so we dont have to worry about duplicates. If the idx == size of the nums, we add our current
tracker. Add the current element to the tracker, call index + 1, pop it when we return, then call index + 1 again. Basic technique
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void subsetsHelper(int idx, int sz, vector<vector<int>> &res, vector<int> &tracker, vector<int> &nums) {
        if(idx >= sz) {
            res.push_back(tracker);
            return;
        }
        tracker.push_back(nums[idx]);
        subsetsHelper(idx + 1, sz, res, tracker, nums);
        tracker.pop_back();
        subsetsHelper(idx + 1, sz, res, tracker, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tracker;
        subsetsHelper(0, nums.size(), res, tracker, nums);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {1, 2, 3};
    cout << sol.subsets(test1) << endl;
    return 0;
}