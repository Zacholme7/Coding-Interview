// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Difficulty: Medium 
// Date solved: May 27, 2023
/*
Solution: 
this problem presents itself as a tree problem but it is a graph problem in a way. we know that the node can be anywhere in the tree and 
we have to traverse both ways (up and down) the tree. We can first construct an adjacency list to keep a tracking of nodes to their parents that will
allow us to move up the tree if we need to. Once we have the parent list, we are able to move back up the tree and down so that allows us to preform a bfs.
We want to do a bfs since we want all the nodes that are a certain distance away, rather than how deep they are. So then we can figure out the distance by maintaining
a queue that will track the nodes currently in the search and the nodes we have visited already. If we are going and we have node see a node in the bfs, we want to add it 
to the visited list and add it to our queue to explore its neighnors. We repeat this for the left child, right child, and parent of each node. Eventually, when our depth hits k
we know our q will contain all the elements that are k distance away and we can just add these to a resulting vector to be returedn
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {                                                                                                             
public:                                                                                                                      
    void makeParentMap(unordered_map<TreeNode*, TreeNode*> &nodeMp, TreeNode *root) {                                        
        queue<TreeNode*> q;                                                                                                  
        q.push(root);                                                                                                        
        while(!q.empty()) {                                                                                                  
            int qSz = q.size();                                                                                              
            for(int i = 0; i < qSz; i++) {                                                                                   
                TreeNode *curr = q.front();                                                                                  
                q.pop();                                                                                                     
                if(curr->left) {                                                                                             
                    nodeMp[curr->left] = curr;                                                                               
                    q.push(curr->left);                                                                                      
                }                                                                                                            
                if(curr->right) {                                                                                            
                    nodeMp[curr->right] = curr;                                                                              
                    q.push(curr->right);                                                                                     
                }                                                                                                            
            }                                                                                                                
        }                                                                                                                    
    }                                                                                                                        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {                                                         
        vector<int> res;                                                                                                     
        if(root == NULL)                                                                                                     
            return res;                                                                                                      
                                                                                                                             
        // make the parent map    
        unordered_map<TreeNode*, TreeNode*> nodeMp;                                                                                           
        makeParentMap(nodeMp, root);                                                                                         
                                                                                                                             
        // do the BFS                                                                                                        
        int currDis = 0;                                                                                                     
        unordered_map<TreeNode*, bool> visited;                                                                              
        queue<TreeNode*> q;                                                                                                  
        q.push(target);                                                                                                      
        visited[target] = true;                                                                                              
                                                                                                                             
        while(!q.empty()) {                                                                                                  
            if(currDis++ == k)                                                                                               
                break;                                                                                                       
            int qSz = q.size();                                                                                              
            for(int i = 0; i < qSz; i++) {                                                                                   
                TreeNode* curr = q.front();                                                                                  
                q.pop();                                                                                                     
                if(curr->left and !visited[curr->left]) {                                                                    
                    q.push(curr->left);                                                                                      
                    visited[curr->left] = true;                                                                              
                }                                                                                                            
                if(curr->right and !visited[curr->right]) {                                                                  
                    q.push(curr->right);                                                                                     
                    visited[curr->right] = true;                                                                             
                }                                                                                                            
                if(nodeMp.count(curr) and !visited[nodeMp[curr]]) {                                                          
                    q.push(nodeMp[curr]);                                                                                    
                    visited[nodeMp[curr]] = true;                                                                           
                }                                                                                                            
            }                                                                                                                
        }                                                                                                                    
                                                                                                                             
        while(!q.empty()) {                                                                                                  
            TreeNode *curr = q.front();                                                                                      
            q.pop();                                                                                                         
            res.push_back(curr->val);
        }

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}