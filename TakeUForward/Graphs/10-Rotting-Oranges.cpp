// link: https://leetcode.com/problems/rotting-oranges/description/
// difficulty: medium
// date solved: july 18, 2024
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> rottenOranges;
    int freshOranges = 0;
    int rows = grid.size(), cols = grid[0].size();

    // Count fresh oranges and add rotten oranges to the queue
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
          rottenOranges.push({i, j});
        } else if (grid[i][j] == 1) {
          freshOranges++;
        }
      }
    }

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    int minutes = 0;

    while (!rottenOranges.empty() && freshOranges > 0) {
      int size = rottenOranges.size();
      for (int k = 0; k < size; k++) {
        auto [row, col] = rottenOranges.front();
        rottenOranges.pop();

        for (int i = 0; i < 4; i++) {
          int newRow = row + dx[i];
          int newCol = col + dy[i];

          if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
              grid[newRow][newCol] == 1) {
            grid[newRow][newCol] = 2;
            rottenOranges.push({newRow, newCol});
            freshOranges--;
          }
        }
      }
      minutes++;
    }

    return freshOranges == 0 ? minutes : -1;
  }
};
