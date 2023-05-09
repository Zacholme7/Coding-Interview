// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Difficulty: Easy
// Date solved: April 22, 2023
/*
Solution: 
This is a very basic binary tree recursion question. We want to find the height of the tree
which is the longest path from the root to a left node. This could be done in an iterative fashion 
using a level order traversal, but recursion is more natual. Your base case is when the root is null,
you want to return 0 since this does not contribrute to the height of the tree. You can then recurse on 
the left and the right halves to get the size. After going to the left and the right, you want to return
the max of the left and right plus 1 for the current node.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}