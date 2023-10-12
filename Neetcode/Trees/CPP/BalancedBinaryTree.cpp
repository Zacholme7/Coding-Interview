// Link: https://leetcode.com/problems/balanced-binary-tree/
// Difficulty: Easy
// Date solved: May 9, 2023
/*
Solution: 
We want to check if any part of the three has a difference in height that is greater than one. The default way to do this is to just take the height
of each side of the tree at each root and compare the two. This means that we will have to take the height for n nodes where n is the number of nodes
in the tree and this is not what we want. Instread, we can just modify the depth algorithm to include this. If the difference is ever greater than one, we
just reutnr -1 instread of the height. After each recursive call, we check if the left or the right height is -1 and we automaitcally know is there is an 
imblance. This allows us to short circuit the computation and at the end if the result is not -1, we know we have a balanced tree, otherwise it is not. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
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

    int isBalancedHelper(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = isBalancedHelper(root->left);
        int rightHeight = isBalancedHelper(root->right);

        if(leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return - 1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) != -1;
    }
};

int main() {
    Solution sol;
    return 0;
}