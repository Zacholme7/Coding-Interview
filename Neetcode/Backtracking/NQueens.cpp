// Link: https://leetcode.com/problems/n-queens/description/
// Difficulty: Hard
// Date solved: May 22, 2023
/*
Solution:
Was able to solve this myself. USE THE RECURSIVE TECHNIQUES AND DRAW OUT THE TREE. This is no more difficult that other problems that I have
currently solved. We follow the pick not pick like we always have. Im my solution I go row by row. For example, place a queen in the 0th row and 0th col
then move onto the next row. Try to place a queen in the 1st row and 0th col, try to place a queen in the 1st row and 1st col. For each of these squares,
have a helper function that will tell you if it is safe. You only need to check the col above since we are not placing below, the upper left and upper right
diagonals since again we are going row by row and not placing anything below or in the same column. The base case is when we reach row = dim of the board, which
means that we were able to find a safe square for all the queens.
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
   

    void solve(int n, int row, vector<vector<string>> &res, vector<string> &tracker) {
        if(n == row) {
            res.push_back(tracker);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
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