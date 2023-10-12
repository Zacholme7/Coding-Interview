// Link: https://leetcode.com/problems/sudoku-solver/description/
// Difficulty: Hard
// Date solved: May 24, 2023
/*
Solution:
I was very close to figuring this out on my own. The only part that I did not understand was how to backtrack properly. I see that if you can not get any of the characters, you need
to backtrack and you need to return false. This can be checked in the inner loop of testing the characters, if solve returns false, that means we failed somewhere down the board and you
need to backtrack by setting the current spot back to a . and try a different character, true is only returned in the solve is we are able to solve the board and we just keep returning once this
happends. I also dont think I would have been able to get the isValid part where is checks the individual square
*/
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) {
                return false;
            }
            if(board[row][i] == c) {
                return false;
            }
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board) == true) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};


int main() {
    Solution sol;
    return 0;
}