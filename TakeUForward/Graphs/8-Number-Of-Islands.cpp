// link: https://leetcode.com/problems/number-of-islands/description/
// difficulty: medium
// date solved: july 16, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    // visited will track what we have searched so far
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    // the number of islands
    int res = 0;

    // go through each element, if it is a 1 we want to do a bfs and visited all connected parts
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[i].size(); j++) {
        // if we have not visited
        if (grid[i][j] == '1' && !visited[i][j]) {
          // mark it as visited and explore it
          dfs(i, j, visited, grid);
          res++;
        }
      }
    }
    return res;
  }


  void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    visited[row][col] = true;
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    // go through all dirs
    for(int i = 0; i < 4; i++) {
      int newRow = row + dx[i];
      int newCol = col + dy[i];

      // if we are inbounds
      if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
        // if it is a one
        if (!visited[newRow][newCol] && grid[newRow][newCol] == '1') {
          // recurse on it
          dfs(newRow, newCol, visited, grid);
        }
      }
    }
  }

};
