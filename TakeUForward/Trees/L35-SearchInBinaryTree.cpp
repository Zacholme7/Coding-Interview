// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Difficulty: Easy
// Date solved: June 20, 2023
// Time: O(logn) where n is the number of nodes in the tree 
// Space: O(1)
/*
Solution: 
This is one of the most fundamental things in datastrctures, a simple bst search.
Just move the root corresponding to the comparison to the value
*/

#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root) {
            if(root->val == val) {
                return root;
            }
            if(root->val < val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return NULL;
    }
};

int main() {
    Solution sol;
    return 0;
}