// Link: https://leetcode.com/problems/binary-search/
// Difficulty: Easy
// Date solved: May 6, 2023
/*
Solution
This is the binary search algorithm. The input is sorted so you can eliminate half of the array on each iteration.
You have a left and a right pointer, calculate the mid, and then compare it to the target. If the mid is the target,
you have found your value, if the mid is less than the target, the target will be to the right of mid, the same goes 
for if it is smaller. You can keep iterating until left <= right and if this fails then the number is not found and you
can return -1
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {-1,0,3,5,9,12};
    cout << sol.search(test1, 9) << " should be 4" << endl;
    cout << sol.search(test1, 2) << " should be -1" << endl;
    return 0;
}