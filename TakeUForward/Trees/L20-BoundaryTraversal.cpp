// Link: https://leetcode.com/problems/boundary-of-binary-tree/
// Difficulty: Medium
// Date solved: May 15, 2023
/*
Solution: 
This is a leetcode premium problem but it is pretty simple. You want to take the boundary traveral of a binary tree in a counter 
clockwise manner. For this, we want to add the left boundary, add the leaves, then add the right boundary. So we have a function for
each. For the left boundary, we go as far left as we can, go right if we cant go left, then keep going left. Repeat this until we are 
at a left node and on each iteration add the value to the result. For the leaves, just do a simple preorder traversal and only add nodes
if they are a leaft node. For the right boundary, do the exact same thing as the left boundary but reverse it for the right side and add the
values to a temporary vector. Just add the values of this tmp vector into the result in reverse order to simulate climbing back up the tree.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isLeafNode(TreeNode *node) {
        return node->left == NULL && node->right == NULL;
    }

    void addLeftBoundary(TreeNode *node, vector<int> &res) {
        TreeNode *cur = node->left;
        while(cur) {
            if(!isLeafNode(cur)) {
                res.push_back(cur->val);
            }
            if(cur->left) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }

    void addLeaves(TreeNode *node, vector<int> &res) {
        if(isLeafNode(node)) {
            res.push_back(node->val);
            return;
        }
        if(node->left) {
            addLeaves(node->left, res);
        }
        if(node->right) {
            addLeaves(node->right, res);
        }
    }

    void addRightBoundary(TreeNode *node, vector<int> &res) {
        TreeNode *cur = node->right;
        vector<int> tmp;
        while(cur) {
            if(!isLeafNode(cur)) {
                tmp.push_back(cur->val);
            }
            if(cur->right) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        for(int i = tmp.size() - 1; i >= 0; i--) {
            res.push_back(tmp[i]);
        }
    }

    vector<int> boundaryTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }

        if(!isLeafNode(root)) {
            res.push_back(root->val);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}