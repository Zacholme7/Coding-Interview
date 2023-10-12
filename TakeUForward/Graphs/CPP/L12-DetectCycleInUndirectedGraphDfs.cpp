// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
// Difficulty: Medium
// Date:  June 21, 2023 
// Space: O(n + 2E) 
// Time: O(n)
/*
Solution:
This is nearly identical to the bfs approach but its just dfs. WE setup the isCycle function call the same with our visited array,
and then loop through and if a node is not visited we do a search on it. This will handle unconnected graphs. From there we do a dfs search.
We maintain a pair of parent to child so that we can tell if we have hit a node that is not a parent and that is already visited. That 
will mean that we have a loop. We extract the values, visit the current node, and loop through its neighbors. The first one that has not
been visited we visit. Else, if a node is visited it either means its the parent or its not the parent and we have a loop. If its not the 
parent we return true to single that there is a cycle and this will continously return true in our detect return. Otherewise we just continue on.
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool detect(pair<int, int> src, vector<int> adj[], vector<bool> &visited) {
        int parent = src.first;
        int node = src.second;
        visited[node] = true;
        for(auto neigh: adj[node]) {
            if(!visited[neigh]) {
                if(detect({node, neigh}, adj, visited))
                    return true;
            } else if (neigh != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        for(int i = 0; i < V; i++) {
            if(visited[i] == false) {
                if(detect({-1, i}, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
};

int main() {
    Solution sol;
    

    return 0;
}
