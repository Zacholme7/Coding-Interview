// link: https://leetcode.com/problems/01-matrix/
// difficulty: medium
// date solved: july 21, 2024
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        // mark all the zeros and track them
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        // do the bfs
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (auto [dr, dc]: dirs) {
                int rowDx = row + dr, colDx = col + dc;
                if (rowDx >= 0 && rowDx < rows && colDx >= 0 && colDx < cols && !visited[rowDx][colDx]) {
                    dist[rowDx][colDx] = dist[row][col] + 1;
                    visited[rowDx][colDx] = true;
                    q.push({rowDx, colDx});
                }
            }
        }
    }
};