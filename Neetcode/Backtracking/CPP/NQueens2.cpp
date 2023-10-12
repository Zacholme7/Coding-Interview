// Link: https://leetcode.com/problems/n-queens-ii/description/
// Difficulty: Hard
// Date solved: May 23, 2023
/*
Solution:
Check description for NQuees for solution. Literally the exact same problem except instead of tracking the actual solutions
I just increment a counter for the number of solutions.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &tracker) {
        // Check the column
        for (int i = 0; i < row; i++)
            if (tracker[i][col] == 'Q')
                return false;

        // Check the main diagonal (top left)
        for (int i=row, j=col; i>=0 && j>=0; i--, j--)
            if (tracker[i][j] == 'Q')
                return false;

        // Check the secondary diagonal (top right)
        for (int i=row, j=col; j<tracker.size() && i>=0; i--, j++)
            if (tracker[i][j] == 'Q')
                return false;

        return true;
    }
   

    void solve(int n, int row, int &res, vector<string> &tracker) {
        if(n == row) {
            res++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, tracker)) {
                tracker[row][col] = 'Q';
                solve(n, row + 1, res, tracker);
                tracker[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int res = 0;
        std::string str (n, '.');
        vector<string> tracker(n, str); 
        solve(n, 0, res, tracker);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}