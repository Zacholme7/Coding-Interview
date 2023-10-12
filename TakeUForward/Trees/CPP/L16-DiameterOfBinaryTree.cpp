// Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Difficulty: Easy
// Date solved: May 10, 2023
/*
Solution: 
This problem off the bat is a bit tricky if you only assume the longest path is through the root. That was my mistake at first. The longest 
path can be in a subtree. We can recursively work our way up the tree and take the max height at each path. So I just have a helper function that 
basically just takes the height of the tree. Althought I add in a diameter variable that will track the max at each itheration. As it works up the tree
this variable will constantly be updated with the new max diameter so that we can return the correct value at the end
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

    int diameterHelper(TreeNode *node, int &diameter) {
        if(node == NULL) {
            return 0;
        }
        int leftHeight = diameterHelper(node->left, diameter);
        int rightHeight = diameterHelper(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int diameter = 0;
        diameterHelper(root, diameter);
        return diameter;
    }
};

int main() {
    Solution sol;
    return 0;
}