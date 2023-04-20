// https://leetcode.com/problems/contains-duplicate/
// Difficulty: Easy
// Date solved: April 19, 2023
/* 
Solution:
This is a simple problem, we want to see if there is a duplicate in the vector nums.
We know that a property of a set is that it cannot contain duplicates. Due to this, we
can compare the size of the vector nums to a set that was constructed from the vector.
If the vector is larger, that means there are duplicates, otherwise there are not.
*/

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(test1) << " should be true" << endl;
    cout << sol.containsDuplicate(test2) << " should be false" << endl;
    return 0;
}