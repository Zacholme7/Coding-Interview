// Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
// Difficulty: Easy
// Date: June 16, 2023
// Space: O(n)
// Time: O(n)
/*
Solution
This is a graph based problem that just operates on a matrix. We can convert this into an adjacency list and solve it 
very easily using a dfs or some transerval, but it is easier to just direclty operate on the grid. This is pretty much the same
as the last problem but instead of using an adj list, we are just working right on the matrix. We make a visited that mirrors the matrix.
We loop through the matrix and when we find a 1 that is not visited, we preform a bfs on it. This will visit all of its possible connected components
and then when we return we will keep looking through to find the next non visited one. If we find another non visited 1, that will mean that its because it
was not reached in our previous traversal so it is not part of that graph, hence on each new finding of an univisted 1 in the main code we can increase the 
counter and then return it at the end
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &nodeQ) {
        while(!nodeQ.empty()) {
            auto dimPair = nodeQ.front(); nodeQ.pop();
            int row = dimPair.first;
            int col = dimPair.second;
            for(int neighRow = -1; neighRow <= 1; neighRow++) {
                for(int neighCol = -1; neighCol <= 1; neighCol++) {
                    int newRow = neighRow + row;
                    int newCol = neighCol + col;
                    if(newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size()){
                        if(grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                            visited[newRow][newCol] = true;
                            nodeQ.push({newRow, newCol});
                        }
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        queue<pair<int, int>> nodeQ;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    numIslands++;
                    nodeQ.push({i, j});
                    bfs(grid, visited, nodeQ);
                }
            }
        }
        return numIslands;
    }
        
};


int main() {
    Solution sol;
    vector<vector<char>> grid = {{'0', '1'}, {'1', '0'},{'1', '1'},{'1', '0'}};
    vector<vector<char>> grid2 = { {'1', '0', '1', '0', '0', '1', '1', '0', '1' }};
    cout << sol.numIslands(grid) << endl;
    cout << sol.numIslands(grid2) << endl;
    return 0;
}