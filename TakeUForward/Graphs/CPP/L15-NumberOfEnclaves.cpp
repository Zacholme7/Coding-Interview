// Link: https://leetcode.com/problems/number-of-enclaves/ 
// Difficulty: Medium
// Date: June 29, 2023
/*
Solution:
This is literally the exact same solution as the previous one. We want to find how many nodes
cannot reach the edge of the grid. So we go through and do a dfs/bfs on all nodes on the edge that
are 1 and then we go back and loop through the grid and if a node is not visited and it is 1 that means we
did not reach it from the edge therefore we increment our counter;
*/

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &board, vector<vector<bool>> &visited) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        visited[row][col] = true;
        for(int delta = 0; delta < 4; delta++) {
            int newRow = row + dx[delta];
            int newCol = col + dy[delta];
            if(newRow >= 0 && newCol >= 0 && newRow < board.size() && newCol < board[0].size()) {
                if(board[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    dfs(newRow, newCol, board, visited);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        int rows = board.size();
        int cols = board[0].size();

        // iterate over top roaw
        for(int col = 0; col < cols; col++) {
            if(board[0][col] == 1 && !visited[0][col]) 
                dfs(0, col, board, visited);
        }

        // right side
        for(int row = 0; row < rows; row++) {
            if(board[row][cols-1] == 1 && !visited[row][cols-1]) 
                dfs(row, cols-1, board, visited);
        }

        // bottom row
        for(int col = 0; col < cols; col++) {
            if(board[rows-1][col] == 1 && !visited[rows-1][col]) 
                dfs(rows-1, col, board, visited);
        }

        // left row
        for(int row = 0; row < rows; row++) {
            if(board[row][0] == 1 && !visited[row][0]) 
                dfs(row, 0, board, visited);
        }

        // mark all not visited as 0
        int numEnclaves = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 1 && !visited[i][j]) {
                    numEnclaves++;
                }
            }
        }
        return numEnclaves;
    }
};

int main() {
    Solution sol;
    return 0;
}
