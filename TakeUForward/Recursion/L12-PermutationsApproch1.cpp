// Link: https://leetcode.com/problems/permutations/description/
// Difficulty: Medium
// Date solved: May 17, 2023
/*
Solution:
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void permuteHelper(vector<int> &tracker, vector<bool> &picked, vector<int> &nums, vector<vector<int>> &res) {
        if(tracker.size() == nums.size()) {
            res.push_back(tracker);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(picked[i] == true) {
                continue;
            }
            tracker.push_back(nums[i]);
            picked[i] = true;
            permuteHelper(tracker, picked, nums, res);
            picked[i] = false;
            tracker.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tracker;
        vector<bool> picked(nums.size(), false);
        permuteHelper(tracker, picked, nums, res);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> test1 {1, 2, 3};
    cout << sol.permute(test1) << endl;
    return 0;
}