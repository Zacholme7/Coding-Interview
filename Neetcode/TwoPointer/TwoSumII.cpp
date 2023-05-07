// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty: Medium
// Date solved: May 7, 2023
/*
Solution
This is a medium problem but could be classified as an easy. This utilizes the two pointer approach to find two numbers that sum up to a target.
What we can do is have a left and right pointer. While the left is not the right, we can find the sum of these two numbers. We are told that the array
is sorted and we can use this in the soluton. In the first iteration, we will be adding the smallest and the largest numbers. If this sum is less than the target,
we know we can move the left pointer by one to get the next largst number. The same goes for it the sum is greater than the target, we can move the right pointer by
one so we get a smaller sum. If the sum is the target, we just return the pointers + 1 since the problem wants 1 based indexing. 
*/

#include <iostream>
#include <vector>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {2 ,7, 11, 15};
    vector<int> test2 = {2, 3, 4};
    vector<int> test3 = {-1, 0};
    cout << sol.twoSum(test1, 9) << " should be [1, 2]" << endl;
    cout << sol.twoSum(test2, 6) << " should be [1, 3]" << endl;
    cout << sol.twoSum(test3, -1) << " should be [1, 2]" << endl;

}