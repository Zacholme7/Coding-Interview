// link: https://leetcode.com/problems/first-missing-positive/?envType=daily-question&envId=2024-03-26
// difficulty: hard
// date solved: march 26, 2024
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};