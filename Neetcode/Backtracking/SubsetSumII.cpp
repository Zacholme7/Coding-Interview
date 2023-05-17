// Link: https://leetcode.com/problems/subsets-ii/
// Difficulty: Medium
// Date solved: May 17, 2023
/*
Solution:
This is another recurisve solution that takes advantage of the technique that we use when we have duplicate element in the array. We want to find every subset
in the array so we dont have a base case per say. On each iteration, the first thing we want to do is add the current tracker to our res because we know we are going
to make it so that this is unique each time. We then do our for loop where i is starting at the idx to represent our pick not pick. We then have the logic to skip picking
a repeat element more than once at first. 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void subsetsWithDupHelper(int idx, vector<vector<int>> &res, vector<int> &tracker, vector<int> &nums) {
        res.push_back(tracker);

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            tracker.push_back(nums[i]);
            subsetsWithDupHelper(i + 1, res, tracker, nums);
            tracker.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tracker;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(0, res, tracker, nums);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {1, 2, 2};
    sol.subsetsWithDup(test1);
    return 0;
}