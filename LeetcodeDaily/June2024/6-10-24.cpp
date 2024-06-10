// link: https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
// difficulty: easy
// date solved: june 10, 2024
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        int counter = 0;

        for(int i = 0; i < heights.size(); i++) {
                if (heights[i] != expected[i]) counter++;
        }

        return counter;
    }
};