// link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
// difficulty: medium
// date solved: july 28 2024
#include <vector>
using namespace std;

class Solution {
public:
  bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
      if (dfs(i, visited, recStack, adj))
        return true;
    }
    return false;
  }

private:
  bool dfs(int node, vector<bool> &visited, vector<bool> &recStack,
           vector<int> adj[]) {
    if (!visited[node]) {
      visited[node] = true;
      recStack[node] = true;

      for (int neighbor : adj[node]) {
        if (!visited[neighbor] && dfs(neighbor, visited, recStack, adj))
          return true;
        else if (recStack[neighbor])
          return true;
      }
    }
    recStack[node] = false;
    return false;
  }
};
