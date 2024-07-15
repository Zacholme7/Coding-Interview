// link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
// difficulty: easy
// date solved: july 14, 2024
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dfsOfGraphIter(int V, vector<int> adj[]) {
    vector<bool> visited;
    vector<int> result;

    dfs(0, adj, visited, result);
    return result;
  }

  void dfs(int node, vector<int> adj[], vector<bool> &visited,
           vector<int> &result) {
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, adj, visited, result);
      }
    }
  }


  vector<int> dfsOfGraphRec(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> result;
    result.reserve(V); // Pre-allocate space for efficiency

    stack<int> st;
    st.push(0); // Start from node 0

    while (!st.empty()) {
      int node = st.top();
      st.pop();

      if (!visited[node]) {
        visited[node] = true;
        result.push_back(node);

        // Push neighbors in reverse order to maintain DFS order
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
          if (!visited[*it]) {
            st.push(*it);
          }
        }
      }
    }

    return result;
  }
};
