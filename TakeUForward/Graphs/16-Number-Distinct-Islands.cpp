// link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
// difficulty: medium
// date solved: july 24, 2024
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  void dfs(int i, int j, vector<vector<int>> &grid, int startI, int startJ,
           string &shape) {
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
      return;

    grid[i][j] = 0;
    shape += to_string(i - startI) + to_string(j - startJ);

    dfs(i + 1, j, grid, startI, startJ, shape);
    dfs(i - 1, j, grid, startI, startJ, shape);
    dfs(i, j + 1, grid, startI, startJ, shape);
    dfs(i, j - 1, grid, startI, startJ, shape);
  }

public:
  int countDistinctIslands(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    set<string> shapes{};
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) { // Only start DFS if it's a land cell
          string shape = "";
          dfs(i, j, grid, i, j, shape);
          if (!shape.empty()) { // Only insert non-empty shapes
            shapes.insert(shape);
          }
        }
      }
    }
    return shapes.size();
  }
};
