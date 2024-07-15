// link: https://leetcode.com/problems/number-of-provinces/
// difficulty: medium
// date solved: july 15, 2024
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    vector<bool> visited(isConnected.size());
    unordered_map<int, vector<int>> adjMap;
    int num = 0;

    for (int i = 0; i < isConnected.size(); i++) {
      for (int j = 0; j < isConnected[i].size(); j++) {
        if (i != j && isConnected[i][j] == 1) {
          adjMap[i].push_back(j);
        }
      }
    }

    for (int i = 0; i < isConnected.size(); i++) {
      if (!visited[i]) {
        bfs(i, visited, adjMap);
        num++;
      }
    }
    return num;
  }

  void bfs(int node, vector<bool> &visited,
           unordered_map<int, vector<int>> &adjMap) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int neighbor : adjMap[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }
};
