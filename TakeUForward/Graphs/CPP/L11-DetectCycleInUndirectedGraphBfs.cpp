// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
// Difficulty: Medium
// Date:  June 20, 2023 
// Space: O(n + 2E) 
// Time: O(n)
/*
Solution:
This is just a twist on a bfs appraoch. The one difference is that we are tracking both the parent and 
the current node. The idea behind this is that we have a cycle, we will be adding it from one node and it will already
be visited. If it is not visited, we do the standard bfs by visiting it and then adding it to the queue. But, the 
part that solves this question is that we need to check if it is the parent of the current node or not. We are looking
for a node that is already visited and that is not the parent of the current node meaning it was visited previoulsy 
by some other path and that will mean we have a cycle. So we also compare the node to check if it is the parent
and return true if it is not since that will mean that we have a cycle
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool detect(int src, vector<int> adj[], vector<bool> &visited) {
        visited[src] = true;
        queue<pair<int, int>> nodeQ;
        nodeQ.push({src, -1});
        while(!nodeQ.empty()) {
            int qSz = nodeQ.size();
            for(int i = 0; i < qSz; i++) {
                int currNode = nodeQ.front().first;
                int parentNode = nodeQ.front().second;
                for(auto neigh: adj[currNode]) {
                    if(!visited[neigh]) {
                        visited[neigh] = true;
                        nodeQ.push({neigh, currNode});
                    } else if (parentNode != neigh) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        for(int i = 0; i < V; i++) {
            if(visited[i] == false) {
                if(detect(i, adj, visited)) {
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
