// link:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
// difficulty: medium
// date solved: july 19, 2024
#include <vector>
using namespace std;

class Solution {
public:
  bool isCycle(int V, vector<int> adj[]) {
    // visited of the length of all the nodes
    vector<bool> visited(V);

    // go through each node, covers cases when there are
    // unconnected components
    for (int i = 0; i < V; i++) {
      // if we have not visited, perform dfs for cycle
      if (!visited[i]) {
        bool ret = dfs(i, -1, visited, adj);
        if (ret == true) {
          return true;
        }
      }
    }
    return false;
  }

private:
  // perform dfs starting at i, if we hit
  bool dfs(int node, int parent, vector<bool> &visited, vector<int> adj[]) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        if (dfs(neighbor, node, visited, adj)) {
          return true;
        }
      } else if (neighbor != parent) {
        return true;
      }
    }
    return false;
  }
};
