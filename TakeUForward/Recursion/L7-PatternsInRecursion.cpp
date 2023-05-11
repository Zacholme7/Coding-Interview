// Video: https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7
// Date: May 11, 2023
// This video just went off some common subsequence modifications: print all answers, print answer once, print number of answers
// Time Complexity: 2 ^ n


#include <vector>
#include <iostream>
#include "../../Util.cpp"
using namespace std;

class Solution{
public:
    void printSubEqualK(int idx, vector<int> &ds, int currSum, int sum, vector<int> &nums, int size) {
        if(idx == size) {
            if(currSum == sum) {
                cout << ds << endl;
            }
            return;
        }
        ds.push_back(nums[idx]);
        currSum += nums[idx];
        printSubEqualK(idx + 1, ds, currSum, sum, nums, size);
        ds.pop_back();
        currSum -= nums[idx];
        printSubEqualK(idx + 1, ds, currSum, sum, nums, size);
    }

    bool printSubEqualKOnce(int idx, vector<int> &ds, int currSum, int sum, vector<int> &nums, int size) {
        if(idx == size) {
            if(currSum == sum) {
                cout << ds << endl;
                return true;
            }
            return false;
        }
        ds.push_back(nums[idx]);
        currSum += nums[idx];
        if(printSubEqualKOnce(idx + 1, ds, currSum, sum, nums, size)) {
            return true;
        }
        ds.pop_back();
        currSum -= nums[idx];
        if(printSubEqualKOnce(idx + 1, ds, currSum, sum, nums, size)) {
            return true;
        };
        return false;
    }

    int printSubEqualKCount(int idx, int currSum, int sum, vector<int> &nums, int size) {
        if(idx == size) {
            if(currSum == sum) {
                return 1;
            }
            return 0;
        }
        currSum += nums[idx];
        int cntAdd = printSubEqualKCount(idx + 1, currSum, sum, nums, size);
        currSum -= nums[idx];
        int cntNotAdd =printSubEqualKCount(idx + 1, currSum, sum, nums, size);
        return cntAdd + cntNotAdd;
    }
};

int main() {
    Solution sol;
    vector<int> test { 1, 2, 1};
    vector<int> ds;
    sol.printSubEqualK(0, ds, 0, 2, test, test.size());
    cout << endl;
    sol.printSubEqualKOnce(0, ds, 0, 2, test, test.size());
    cout << endl;
    cout << sol.printSubEqualKCount(0, 0, 2, test, test.size()) << endl;
    return 0;
}