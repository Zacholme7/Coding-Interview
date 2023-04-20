// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy
// Date solved: April 19, 2023
/*
Solution:
A preorder traversal is one of the fundamental traversals of a tree. It follows the path of root, left, right.
For the problem, we are asked to return a vector of the nodes in the tree in a preorder traversal manner.
For this, I set up a vector to hold the result, and called a recursive helper function to populate the vector.
The base case is when the node is null, meaning we cannot go any further down that path. Otherwise, I add the
node to the vector (root), traverse down the left side (left), and then traverse down the right side (right).
At the end I just return the populated vector.
*/

#include <iostream>
#include <vector>
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
    void preorderHelper(vector<int> &res, TreeNode *node) {
        if(node == NULL) return;
        res.push_back(node->val);
        preorderHelper(res, node->left);
        preorderHelper(res, node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        preorderHelper(res, root);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}


