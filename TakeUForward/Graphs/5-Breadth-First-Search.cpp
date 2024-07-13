// link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
// difficulty: easy
// date solved: July 13, 2024
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> bfs;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    return bfs;
  }
};
