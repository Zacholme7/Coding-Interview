// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19
// difficulty: medium
// date solved: january 19, 2024

#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  void helper(int currRow, int currCol, int &minPath, int currPath, vector<vector<int>> &matrix) {
    // if we have went through all the rows
    if (currRow == matrix.size()) {
      // get the new min values
      minPath = min(currPath, minPath);
      return;
    }

    // move down
    helper(currRow + 1, currCol, minPath, currPath + matrix[currRow][currCol], matrix);

    // move left
    if (currCol > 0) {

      helper(currRow + 1, currCol - 1, minPath, currPath + matrix[currRow][currCol - 1], matrix);
    }

    // move right
    if (currCol < matrix[0].size() - 1) {
      helper(currRow + 1, currCol + 1, minPath, currPath + matrix[currRow][currCol + 1], matrix);
    }


  }
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int minPath = INT_MAX;

    for (int col = 0; col < matrix[0].size(); col++) {
      helper(0, col, minPath, 0, matrix);
    }

    return minPath;
  }
};


int main() { return 0; }
