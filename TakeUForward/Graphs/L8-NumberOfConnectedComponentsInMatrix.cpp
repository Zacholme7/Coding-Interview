// Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
// Difficulty: Easy
// Date: June 16, 2023
// Space: O(n)
// Time: O(n)
/*
Solution
I think I overengineered this solution and that it could be simpler. Just because I made it hard I think this should be a 
medium. My idea behind it is very simple. It was just like the last one, just construct a adj list and count the islands. 
Except this is a 1 0 matrix so I have to convert it into an integer grid so I could make the adj list and then had to make the
adjList from the grind. From there is just the same as the last problem, a simple dfs


*/

#include <vector>
#include <queue>
#include <unordered_map>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:

    unordered_map<int, vector<int>> constructAdjList(vector<vector<int>> &grid) {
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        unordered_map<int, vector<int>> adjList;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] != 0) {
                    adjList[grid[row][col]] = vector<int>();
                    for(int k = 0; k < 8; k++) {
                        int ni = row + dx[k];
                        int nj = col + dy[k];

                        if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size()) {
                            if(grid[ni][nj] != 0) {
                                adjList[grid[row][col]].push_back(grid[ni][nj]);
                            }
                        }
                    }
                }
            }
        }
        return adjList;
    }

    vector<vector<int>> constructIntGrid(vector<vector<char>> &grid) {
        int counter = 1;
        vector<vector<int>> intGrid;
        for(int row = 0; row < grid.size(); row++) {
            vector<int> tmp;
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == '1') {
                    tmp.push_back(counter++);
                } else {
                    tmp.push_back(0);
                }
            }
            intGrid.push_back(tmp);
        }
        return intGrid;

    }

    void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adjList) {
        visited[node] = true;
        for(auto neigh: adjList[node]) {
            if(!visited[neigh]) {
                dfs(neigh, visited, adjList);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // adjust grid to be ints and incremental
        int res = 0;
        vector<vector<int>> intGrid = constructIntGrid(grid);
        unordered_map<int, vector<int>> adjList = constructAdjList(intGrid);
        vector<bool> visited(adjList.size() + 1);

        cout << intGrid << endl;
        for(auto it: adjList) {
            cout << it.first << " " << it.second <<endl;
        }


        for(auto pair: adjList) {
            if(!visited[pair.first]) {
                res++;
                dfs(pair.first, visited, adjList);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> grid = {{'0', '1'}, {'1', '0'},{'1', '1'},{'1', '0'}};
    vector<vector<char>> grid2 = { {'1', '0', '1', '0', '0', '1', '1', '0', '1' }};
    cout << sol.numIslands(grid2) << endl;
    return 0;
}