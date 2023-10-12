// Link: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium
// Date: July 18, 2023
/*
Solution:
This is a farily simple problem which i nearly solved on my first attempt. The idea is that we just want to color the entire graph
and look for discrepances. We loop through in the main call incase there are unconnected compoennts of the graph. For each component. We 
color the nodes in an alternating fashion and if a node is already color, we check to see if it is the opposite color of what are are currently coloring.
If it is, then that it okay, if it is not, that means that we cannot color the graph and it is not bipartite.
*/

#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

class Solution {
public:
    bool check(int start, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> queue;
        queue.push(start);
        color[start] = 0;

        while(!queue.empty()) {
            int currNode = queue.front(); queue.pop();
            for(auto it: graph[currNode]) {
                if(color[it] == -1){
                    color[it] = !color[currNode];
                    queue.push(it);
                } else if(color[it] == color[currNode]) {
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> color(graph.size(), -1);
        // handle case where graphs are not connected
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(check(i, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    return 0;
}

