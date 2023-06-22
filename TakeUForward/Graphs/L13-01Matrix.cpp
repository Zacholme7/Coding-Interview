// Link: https://leetcode.com/problems/01-matrix/description/
// Difficulty: Medium
// Date:  June 22, 2023 
/*
Solution:
Got TLE at first approach since I was preforming a bfs on every single node but it was the corrrect solution. This appraoch just performs a 
bfs once and checks each node once. At first you go through and add every single 0 nodes coordiantes and a distnace of 0 since that is where 
each one is started out at. You then perform a bfs on the nodes in this queue. while it is not emtpy, you take the first element and mark
down its distance. Fromt here, you iterate in the 4 directions. We have already taken all the nodes which are 0 so we dont want any more of those,
we are only concerned about if there is a 1 nearby. So if we do see a 1 and it is the firs time it has been visited, we mark it as visited
and add its coords plus an incremented distance to the queue. This will make sure we can explore this path future and we can mark down its current
distance into the result when it is popped off the queue.
*/

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void bfs(queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &mat, vector<vector<bool>> &visited, vector<vector<int>> &res) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto ele = q.front(); q.pop();
            int currRow = ele.first.first;
            int currCol = ele.first.second;
            int dist = ele.second;
            res[currRow][currCol] = dist;
            for(int delta = 0; delta < 4; delta++) {
                int newRow = currRow + dx[delta];
                int newCol = currCol + dy[delta];

                if(newRow >= 0 && newCol >= 0 && newRow < mat.size() && newCol < mat[0].size()) {
                    if(mat[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({{newRow, newCol}, dist + 1});
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size()));
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size()));
        queue<pair<pair<int, int>, int>> q;
        for(int row = 0; row < mat.size(); row++) {
            for(int col = 0; col < mat[0].size(); col++) {
                if(mat[row][col] == 0) {
                    q.push({{row, col}, 0});
                    visited[row][col] = true;
                }
            }
        }
        bfs(q, mat, visited, res);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> test1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> test2 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    cout << sol.updateMatrix(test1) << endl;
    cout << sol.updateMatrix(test2) << endl;
    return 0;
}
