// Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
// Difficulty: Easy
// Date: June 14, 2023
/*
This is again similar to a dfs on a tree in the recursive nature, but it also has similarities to the recursive problems that I have seen.
The main this is that we need to set up our visited list. This is what makes it work. For a dfs, we want to take the first node that we last put in
which naturally leads itself to recursion. We have a helper funciotn in which we immediately mark the node as visited, add it to our result, and then loop
through the neighbors, we check for the ones that are not visited and call the function on each of them. This will make sure that we are going in a depth first manner
and we are not doing all of one nodes neighbors before moving onto the next
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    void dfsHelper(vector<bool> &visited, vector<int> adj[], vector<int> &res, int node) {
        visited[node] = true;
        res.push_back(node);
        for(auto neighbor: adj[node]) {
            if(!visited[neighbor]) {
                dfsHelper(visited, adj, res, neighbor);
            }
        }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        vector<int> res;
        dfsHelper(visited, adj, res, 0);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
