// Link: https://leetcode.com/problems/permutations/description/
// Difficulty: Medium
// Date solved: May 17, 2023
/*
Solution:
We want to take all the possible permutations of the given input list. this is different from subsets. Each idx can be a starting. We follow the same pick not
pick structure with a twist. We want to maintain a list of the ones that we have picked and that we have not picked. This will make it so that we dont 
take the same permutation starting with the same parent. For example, if we have the list [1, 2, 3] and we are starting at 2, we want to mark 2 as picked so that 
when we recurse and start the iteration again, we can pick 1. Here again we mark this as picked and we can take three on the next iteration, we can then unmark 1
as picked, we see that 2 is picked, and then we can mark 3 and pick it. on the next call we will see 1 is not picked so we can pick that and get [2, 3, 1]. We then 
see that the rest are picked and we have got all the numbers that we can. 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../../Util.cpp"
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