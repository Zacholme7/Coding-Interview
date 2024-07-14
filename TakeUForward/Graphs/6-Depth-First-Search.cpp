// link:
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
// difficulty: easy
// date solved: july 14, 2024
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> stack;
    vector<int> res;

    // Start DFS from node 0
    stack.push(0);

    while (!stack.empty()) {
      int node = stack.top();
      stack.pop();

      if (!visited[node]) {
        visited[node] = true;
        res.push_back(node);

        // Push neighbors to stack in reverse order
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
          if (!visited[*it]) {
            stack.push(*it);
          }
        }
      }
    }

    return res;
  }
};
