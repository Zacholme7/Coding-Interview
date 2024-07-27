// link: https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// difficulty: medium
// date solved: July 25, 2024
#include <vector>

using namespace std;
class Solution {
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
        for (int start = 0; start < V; start++) {
            if (color[start] == -1) {
                if (!dfs(start, 0, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool dfs(int node, int currentColor, vector<int> adj[], vector<int>& color) {
        color[node] = currentColor;
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currentColor, adj, color)) {
                    return false;
                }
            } else if (color[neighbor] == currentColor) {
                return false;
            }
        }
        return true;
    }
};
