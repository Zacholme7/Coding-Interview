// link: https://leetcode.com/problems/island-perimeter/?envType=daily-question&envId=2024-04-18
// difficulty: easy
// date solved: april 18, 2024
// writeup: we can do this iteratively. for each square, we know it can contribute at most
// 4 sides so we add that initially. we then check the square to its left and above it. If 
// this square is also land, we subtract 2 to account for the previous square and the current 
// one since they share a border

#include <vector>
using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int perimeter = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for(int r = 0; r < rows; r++) {
      for(int c = 0; c < cols; c++) {
        if (grid[r][c] == 1) {
          perimeter += 4;

          // square to left
          if (r > 0 && grid[r-1][c] == 1) {
            perimeter -= 2;
          }

          // square above
          if (c > 0 && grid[r][c-1] == 1) {
            perimeter -= 2;
          }
        }
      }
    }
    return perimeter;
  }
};
