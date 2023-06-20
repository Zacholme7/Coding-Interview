// Link:https://leetcode.com/problems/rotting-oranges/description/
// Difficulty: Medium
// Date:  June 19
// Space: O(m x n)
// Time: O(m x n)
/*
Solution:
A pretty simple medium problem. This is just a variation of a bfs approach. Basically, we want to find the amount of time
it takes to traverse the entire graph with a bfs approach. First I go through and find where the first orange is rotton and 
add the coords to a queue. I then preform a simple bfs of this and count the number of iterations it takes in the function. 
I traverse in the four directions and check if the node is 1 meaning that it is fresh. From there, I add the coords and set it
to 2 to indicate that it is rotton. This can save us having to pass a visited array. They didnt say anything about it having to
stay intact. From there, we want to loop through again and check if there are any fresh oranges left and if there are we return
-1 since we could not reach it, otherwise we return the minutes. We have to check if the minutes is -1 as this will single that 
there was no rotton organges to begin with and just return 0 in this case. This is a bit of a hack and theres a way around it by
tracking the minute with the pair but this is just extra. 
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int bfs(queue<pair<int, int>> &cordQ, vector<vector<int>> &grid) {
        int minutes = -1;
        int dxA[] = {-1, 1, 0, 0};
        int dyA[] = {0, 0, -1, 1};
        while(!cordQ.empty()) {
            int qLen = cordQ.size();
            for(int i = 0; i < qLen; i++) {
                auto cords = cordQ.front(); cordQ.pop();
                int row = cords.first;
                int col = cords.second;

                for(int d = 0; d < 4; d++){
                    int dRow = row + dxA[d];
                    int dCol = col + dyA[d];
                    if(dRow >= 0 && dCol >= 0 && dRow < grid.size() && dCol < grid[0].size()) {
                        if(grid[dRow][dCol] == 1) {
                            grid[dRow][dCol] = 2;
                            cordQ.push({dRow, dCol});
                        }
                    }
                }
            }
            minutes++;
        }
        return minutes;
    }


    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> cordQ;
        for(int startRow = 0; startRow < grid.size(); startRow++) 
            for(int startCol = 0; startCol < grid[0].size(); startCol++) 
                if(grid[startRow][startCol] == 2) 
                    cordQ.push({startRow, startCol});

        int mins = bfs(cordQ,grid);

        for(int i = 0; i < grid.size(); i++) 
            for(int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == 1) 
                    return -1;

        return mins == -1 ? 0 : mins;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> test1{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> test2{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    vector<vector<int>> test3{{0, 2}};
    vector<vector<int>> test4{{0}};
    cout << sol.orangesRotting(test1) << endl;
    cout << sol.orangesRotting(test2) << endl;
    cout << sol.orangesRotting(test3) << endl;
    cout << sol.orangesRotting(test4) << endl;

    return 0;
}
