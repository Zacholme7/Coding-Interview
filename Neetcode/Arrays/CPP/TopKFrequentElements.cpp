// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty: Medium
// Date solved: April 24, 2023
/*
Solution:
This is a problem that can be solved in a few different ways. I went a standard way. I first started by adding
all the elements to a map with the number as the key and the frequency as the value. From there, I make a priority 
queue which has pairs where they frequency was the first value and the actual number was the second value. We can then just
looop while the pq is not empty and we still have k left and add teh values to a resulting array to be returned.
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
#include "../../../Util.cpp"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> numMap;
        // add elements to map
        for(int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
        }

        // make pq of pairs of elements in the map, priority on freq
        for(auto i: numMap) {
            pq.push({i.second, i.first});
        }

        vector<int> res;
        // add the elements to result
        while(k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> test1 = {1, 1, 1, 2, 2, 3};
    vector<int> test2 = {1};
    cout << sol.topKFrequent(test1, 2) << " should be [ 1 2 ]" << endl;
    cout << sol.topKFrequent(test2, 1) << " should be [ 1 ] " << endl;
    return 0;
}
