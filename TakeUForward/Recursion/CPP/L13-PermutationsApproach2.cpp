// Link: https://leetcode.com/problems/permutations/description/
// Difficulty: Medium
// Date solved: May 22, 2023
/*
Solution:
This is definitely a tricky approach but it makes it so that we dont have to store the extraneous array to track what we have and have not see. The idea behid this
is that we can iterate over the array, but we want to swop the positions to generate the new permutations. We have a constant swap index (idx) that we swap
with the ith value on each iteration. this will generate us a nwe permuation each time. I have a helper to do the swaping and the base case is when we reach past the 
last index and we want to add the result at that time which will be a new permutaiton. In the main loop, I swap with the swapPos and the ith positon, then incrase the 
swap pos to move onto the next element. on the return of the function call, I restore the original array and the ith position is increased so we can swap new elements
and create a new permutation. 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../../Util.cpp"
using namespace std;

class Solution {
public:
    void swap(int from, int to, vector<int> &nums) {
        int tmp = nums[to];
        nums[to] = nums[from];
        nums[from] = tmp;
    }

    void permuteHelper(int idx, vector<int> &nums, vector<vector<int>> &res) {
        if(idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            swap(idx, i, nums);
            permuteHelper(idx + 1, nums, res);
            swap(i, idx, nums);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(0, nums, res);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> test1 {1, 2, 3};
    cout << sol.permute(test1) << endl;
    return 0;
}