// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Difficulty: Easy
// Date solved: April 21, 2023
/*
Solution:
This another form of traversal. The key to this is to use a queue and loop through each level.
We can add the root to a q and loop while the q is not empty. At each iteration, we want to loop
through the length of the queue so we can go through the entire level and add all of the children
at the level below. You also add all of the values to a temporary vector and then add the level
to the main resulting vector. Return at the end 
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // check if null
        if(root == NULL) return res;
        
        // setup q
        queue<TreeNode*> q;
        q.push(root);

        // loop while q not empty
        while(!q.empty()) {
            vector<int> level;

            // go through all nodes in q
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                // add children to q 
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}