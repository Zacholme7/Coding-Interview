// Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
// Difficulty: Medium
// Date: July 9, 2023
/*
Solution:
This is just the same type of problem as we have seen. We loop through and we do a dfs/bfs on a non visited 1. The only thing that we need to 
do differently here is that we need to make sure that the islands are distinct, so we need a way of tracking the shape of the island. We can do 
this by taking the base row and col and subtracting it by the current row and col. This will store the same shape of two of the same islands.
When we add it to the set it will only keep one of the islands and we can just return the legnth of the set at the end. 
*/

#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> currPath, int baseRow, int baseCol) {
        visited[row][col] = true;
        currPath.push_back({row - baseRow, col - baseCol});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int currRow = row + dx[i];
            int currCol = col + dy[i];
            if( currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid.size() && visited[currRow][currCol] == false && grid[currRow][currCol] == 1) {
                dfs(currRow, currCol, grid, visited, currPath, baseRow, baseCol);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == false && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, visited, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


int main() {
    Solution sol;
    return 0;
}