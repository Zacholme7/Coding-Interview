// link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
// difficulty: medium
// date solved: july 19, 2024
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (bfs(i, V, adj, visited)) {
          return true; // Cycle detected
        }
      }
    }
    return false; // No cycle found
  }

private:
  bool bfs(int start, int V, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> nodes;
    nodes.push(make_pair(start, -1));
    visited[start] = true;

    while (!nodes.empty()) {
      int node = nodes.front().first;
      int parent = nodes.front().second;
      nodes.pop();

      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          nodes.push(make_pair(neighbor, node));
        } else if (neighbor != parent) {
          return true; // Cycle detected
        }
      }
    }
    return false; // No cycle found in this component
  }
};
