// link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
// difficulty: medium
// date solved: january 3, 2024
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string> &bank) {
        int totalBeams = 0;
        int prevOnesCount = 0;

        for(const auto &row: bank) {
            int onesCount = std::count(row.begin(), row.end(), '1');
            if (onesCount > 0) {
                if (prevOnesCount > 0) {
                    totalBeams += onesCount + prevOnesCount;
                }
                prevOnesCount = onesCount;
            }
        }

        return totalBeams;
    }
};

int main() {
    Solution sol;
    vector<string> test1 = {"011001", "000000", "010100", "001000"};
    cout << sol.numberOfBeams(test1) << endl;
    return 0;
}
