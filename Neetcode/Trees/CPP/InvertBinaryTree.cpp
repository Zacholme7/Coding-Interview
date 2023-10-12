// Link: https://leetcode.com/problems/invert-binary-tree/
// Difficulty: Easy
// Date solved: May 23, 2023
/*
Solution: 
This is just testing on a depth first seach. we want to recurse to the left nodes, swap the children, then work the way back up. At each parent we swap the two children then move to the next node 
in the dfs and swap their children. At the end we will swap the children of the root where each of the subtrees are already swaped then we can just return the root.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};

int main() {
    Solution sol;
    return 0;
}