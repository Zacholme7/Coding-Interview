// Link: No leetcode link
// Difficulty: Easy
// Date solved: May 16, 2023
/*
Solution:
This was not on leetcode but it is very basic. Just want to get the sum of all the subsets in the candidaites. When the idx == size of the list
that is the base case and we add the sum to our resulting list. Our first recursive call is a pick, and the second is a not pick. Very basic 
recursive structure.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void subsetSumHelper(int idx, int currSum, int sZ, vector<int> &res, vector<int> &candidates) {
        if(idx == sZ) {
            res.push_back(currSum);
        }

        subsetSumHelper(idx + 1, currSum + candidates[idx], sZ, res, candidates);
        subsetSumHelper(idx + 1, currSum, sZ, res, candidates);
    }
    vector<int> subsetSum(vector<int>& candidates) {
        vector<int> res;
        vector<int> tracker;
        subsetSumHelper(0, 0, candidates.size(), tracker, candidates);
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}