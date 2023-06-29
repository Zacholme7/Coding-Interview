// Link: https://leetcode.com/problems/surrounded-regions/ 
// Difficulty: Medium
// Date:  June 23, 2023 
/*
Solution:
The key to this problem is that any sequence of O's that are connected to an O on the edge will NOT be surrounded. We know that any other group of O's that 
have no conneciton to the edge will be surrounded. So we can loop through all of the outer edges and do a bfs or dfs on the outer path of Os. We check that it
hasnt been visited and then do the search. Once this is done, it will make it so that we have a visited matrix taht will mark all of the unsurrounded O's as visited.
We can then loop through and check for each unvisited O and then change it to an X because we know this is not reachable from the edges so it must be surrounded.
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

    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &visited) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        visited[row][col] = true;
        for(int delta = 0; delta < 4; delta++) {
            int newRow = row + dx[delta];
            int newCol = col + dy[delta];
            if(newRow >= 0 && newCol >= 0 && newRow < board.size() && newCol < board[0].size()) {
                if(board[newRow][newCol] == 'O' && !visited[newRow][newCol]) {
                    dfs(newRow, newCol, board, visited);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        int rows = board.size();
        int cols = board[0].size();

        // iterate over top roaw
        for(int col = 0; col < cols; col++) {
            if(board[0][col] == 'O' && !visited[0][col]) 
                dfs(0, col, board, visited);
        }

        // right side
        for(int row = 0; row < rows; row++) {
            if(board[row][cols-1] == 'O' && !visited[row][cols-1]) 
                dfs(row, cols-1, board, visited);
        }

        // bottom row
        for(int col = 0; col < cols; col++) {
            if(board[rows-1][col] == 'O' && !visited[rows-1][col]) 
                dfs(rows-1, col, board, visited);
        }

        // left row
        for(int row = 0; row < rows; row++) {
            if(board[row][0] == 'O' && !visited[row][0]) 
                dfs(row, 0, board, visited);
        }

        // mark all not visited as 0
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    Solution sol;
    return 0;
}
