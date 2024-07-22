// link: https://leetcode.com/problems/surrounded-regions/
// difficulty: medium
// date solved: july 22, 2024
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int rows = board.size();
    if (rows == 0)
      return;
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;

    // Top row
    for (int j = 0; j < cols; j++) {
      if (board[0][j] == 'O') {
        q.push({0, j});
        visited[0][j] = true;
      }
    }
    // Right column, don't double count top right
    for (int i = 1; i < rows; i++) {
      if (board[i][cols - 1] == 'O') {
        q.push({i, cols - 1});
        visited[i][cols - 1] = true;
      }
    }
    // Bottom row, don't double count bottom left/right
    for (int j = cols - 2; j > 0; j--) {
      if (board[rows - 1][j] == 'O') {
        q.push({rows - 1, j});
        visited[rows - 1][j] = true;
      }
    }
    // Left column, don't double count top left
    for (int i = rows - 1; i > 0; i--) {
      if (board[i][0] == 'O') {
        q.push({i, 0});
        visited[i][0] = true;
      }
    }

    // visit every O we can reach from the edge
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (const auto &dir : dirs) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];
        // if in bounds and is an O
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
          // if is an O and we have not visited it
          if (!visited[newRow][newCol] && board[newRow][newCol] == 'O') {
            q.push({newRow, newCol});
            visited[newRow][newCol] = true;
          }
        }
      }
    }

    // mark every O that has not been visited
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (!visited[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
