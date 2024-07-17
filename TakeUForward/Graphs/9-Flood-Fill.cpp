// link: https://leetcode.com/problems/flood-fill/description/
// difficulty: easy
// date solved: july 17, 2024
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    vector<vector<bool>> visited(image.size(),
                                 vector<bool>(image[0].size(), false));
    int startingColor = image[sr][sc];
    bfs(image, sr, sc, visited, startingColor, color);
    return image;
  }

  void dfs(vector<vector<int>> &image, int sr, int sc,
           vector<vector<bool>> &visited, int startingColor, int newColor) {
    image[sr][sc] = newColor;
    visited[sr][sc] = true;

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int newRow = sr + dx[i];
      int newCol = sc + dy[i];

      if (newRow >= 0 && newRow < image.size() && newCol >= 0 &&
          newCol < image[0].size()) {
        if (!visited[newRow][newCol] &&
            image[newRow][newCol] == startingColor) {
          dfs(image, newRow, newCol, visited, startingColor, newColor);
        }
      }
    }
  }

  void bfs(vector<vector<int>> &image, int sr, int sc,
           vector<vector<bool>> &visited, int startingColor, int newColor) {
    queue<pair<int, int>> q;
    q.push({sr, sc});

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
      auto [row, col] = q.front();
      visited[row][col] = true;
      image[col][col] = newColor;

      q.pop();

      for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < image.size() && newCol >= 0 &&
            newCol < image[0].size()) {
          if (!visited[newRow][newCol] &&
              image[newRow][newCol] == startingColor) {
            q.push({newRow, newCol});
          }
        }
      }
    }
  }
};
