// link: https://leetcode.com/problems/longest-increasing-subsequence/?envType=daily-question&envId=2024-01-05
// difficulty: medium
// date solved: january 5, 2023
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            // get the place in the vector where nums[i] should be inserted
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);

            // if the iterator is at the end, this number is greater than everything in the vector, else replace the number
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> test2 = {0, 1, 0, 3, 2, 3};
    vector<int> test3 = {7, 7, 7, 7, 7, 7};
    cout << sol.lengthOfLIS(test1) << endl;
    cout << sol.lengthOfLIS(test2) << endl;
    cout << sol.lengthOfLIS(test3) << endl;
}
