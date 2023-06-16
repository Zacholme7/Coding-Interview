// Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
// Difficulty: Easy
// Date: June 15, 2023
// Space: O(n)
// Time: O(n) for the loop + O(V + 2E) for the dfs
/*
Solution
This is a simple graph problem that utilizes the search algorithms. You can complete this with either. We want to find the number of distinct graphs
in the vetex/edge set and keep track of the number. We are given a weird adj list in this problem so the first thing I do is convert it to something
that is easy to work with. I then just loop throught the number of nodes and perform a dfs on whichever one is not visited. This is because we will
call dfs on a node and it will explore its entire graph so we can increment the number. In the loop, then when we hit another that is not visited
we know this is a new provice/graph so we can increase the counter and explore it again, etc. return the value at the end
*/

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:

    void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        visited[node] = true;
        for(auto neigh : adj[node]) {
            if(!visited[neigh]) {
                dfs(neigh, visited, adj);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V);
        unordered_map<int, vector<int>> mpAdj;
        int numProvinces = 0;

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                if(i != j && adj[i][j] == 1) {
                    mpAdj[i].push_back(j);
                }
            }
        }


        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                numProvinces++;
                dfs(i, visited, mpAdj);
            }
        }
        return numProvinces;
    }
};


int main() {
    Solution sol;
    return 0;
}