// Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
// Difficulty: Easy
// Date: June 9, 2023
/*
This is like a bfs on a tree with a twist. We have an adjacency list where the idx is the node and the value at each idx is the 
neightnors for each node. We want to maintain a visited array to track where we have been and use a queue for the iteration. Add 
the first node to the queue and mark it as visited. While there are nodes in the queue, take the front one, add it to our result,
and loop through its negitnors. if we have not visited a neighbor, add it to the queue and mark it as visited.
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V); // make visited vector
        visited[0] = true; // mark virst node as visited
        queue<int> nodes;
        nodes.push(0);
        vector<int> bfs;
        while(!nodes.empty()) {
            int currNode = nodes.front(); nodes.pop();
            bfs.push_back(currNode);
            for(auto it: adj[currNode]) {
                if(!visited[it]) {
                    visited[it] = true;
                    nodes.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    Solution sol;
    return 0;
}
