// link: https://leetcode.com/problems/number-of-enclaves/description/
// difficulty: medium
// date solved: july 23, 2024
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Check all border cells
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) &&
            grid[i][j] == 1) {
          visited[i][j] = true;
          q.push({i, j});
        }
      }
    }

    // perform a bfs on it now
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, 1, 0, -1};

      for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
          if (!visited[newRow][newCol] && grid[newRow][newCol] == 1) {
            visited[newRow][newCol] = true;
            q.push({newRow, newCol});
          }
        }
      }
    }

    // see if there are any left
    int counter = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (!visited[i][j] && grid[i][j] == 1) {
          counter++;
        }
      }
    }
    return counter;
  }
};
