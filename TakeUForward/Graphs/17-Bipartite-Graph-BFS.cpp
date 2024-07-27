// link: https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// difficulty: medium
// date solved: July 25, 2024
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
      if (color[start] == -1) {
        if (!bfs(start, adj, color)) {
          return false;
        }
      }
    }
    return true;
  }

  bool bfs(int start, vector<int> adj[], vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
          color[neighbor] = 1 - color[node];
          q.push(neighbor);
        } else if (color[neighbor] == color[node]) {
          return false;
        }
      }
    }
    return true;
  }
};
