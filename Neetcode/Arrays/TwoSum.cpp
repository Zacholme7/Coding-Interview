// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Date solved: April 21, 2023
/*
Solution:
This is a pretty simple solution that requires a bit of a trick with a map. We should notice that every
number has a counterpart that adds up to the target. What we can do is subtract the current number
from the target and this will give us the number we need to complete the solution. The other key to this
is that we should look this remaining number up in a hashmap. If the number is in there, that means we have a
match, otherwise, we do not have a match or we just havent seen it yet. Then you just return the corresponding
indicies
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++) {
            int currNum = nums[i];
            int remaining = target - currNum;
            if(numMap.find(remaining) != numMap.end()) {
                return {numMap[remaining], i};
            }
            numMap[currNum] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> test2 = {3, 2, 4};
    vector<int> test3 = {3, 3};
    cout << sol.twoSum(test1, 9) << " should be [0, 1]" << endl;
    cout << sol.twoSum(test2, 6) << " should be [1, 2]" << endl;
    cout << sol.twoSum(test3, 6) << " should be [0, 1]" << endl;
    return 0;
}

