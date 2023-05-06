// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Difficulty: Easy
// Date solved: April 20, 2023
/*
Solution:
A postorder traversal is one of the fundamental traversals of a tree. It follows the path of left, right, root.
For the problem, we are asked to return a vector of the nodes in the tree in a postorder traversal manner.
For this, I set up a vector to hold the result, and called a recursive helper function to populate the vector.
The base case is when the node is null, meaning we cannot go any further down that path. Otherwise, I travel all 
the way down the left side (left), all the way down the right side (Right), then add the root to the vector (Root). 
At the end, you can just return the resulting vector
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
    void postorderHelper(vector<int> &res, TreeNode *node) {
        if(node == NULL) return;
        postorderHelper(res, node->left);
        postorderHelper(res, node->right);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        postorderHelper(res, root);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}