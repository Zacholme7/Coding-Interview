// Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Difficulty: Medium 
// Date solved: May 29, 2023
/*
Solution: 
Once I saw the solution in the video this was super simple to code and understand. We know that the tree is a complete binary tree and we want to find the amount 
of nodes in less than O(n) time. This means that we cant just go and search through every node in the tree. We also know that on the last level the nodes will be as left as possible.
This means that one of the subtrees will be a compeltel binary tree and we dont even need to count all the nodes, we can just exploit that property. For each node, we check the left and 
the right height. If they are the same, that means that the subtrees are both complete trees and we can calculate the total nodes with 2 * height - 1 and then add one for the root.
Otherwise, if they do not match, that means one is not a complete tree, most likely the left, and we go down to the children and check for complete trees there, returing the sums of the 
amount of nodes in each. this way we are not checkign all of the nodes, only getting the left and right heights and using the formula to do the rest
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
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
    int getLeftHeight(TreeNode *node) {
        int level = 0;
        while(node) {
            level++;
            node = node->left;
        }
        return level;
    }

    int getRightHeight(TreeNode *node) {
        int level = 0;
        while(node) {
            level++;
            node = node->right;
        }
        return level;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getRightHeight(root->right);

        if(leftHeight == rightHeight) {
            return 1 + (pow(2, leftHeight) - 1) + (pow(2, rightHeight) - 1);
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};


int main() {
    Solution sol;
    return 0;
}