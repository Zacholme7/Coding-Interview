// Link: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Easy
// Date solved: May 22, 2023
/*
Solution: 
Pretty much the exact same solution as isSameTree(L18), but we just adjust the order of the nodes, we dont want to know if we have the same
tree, we want to know if they are symmetrical. So on each recusrive case we want to go to the left and the right, and then the right and the left.
The trees should be a reflection. Base case if when they are both null, return true. If one is null and one is not, return false. If the values are not
the same, return false. Can short circuit since if one returns false, dont care what the other is and we can just return false
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

    bool isSymmetricHelper(TreeNode *leftNode, TreeNode *rightNode) {
        if(leftNode == NULL && rightNode == NULL) {
            return true;
        } else if (leftNode == NULL || rightNode == NULL) {
            return false;
        } else if (leftNode->val != rightNode->val) {
            return false;
        }

        bool isSymmetricLeft = isSymmetricHelper(leftNode->left, rightNode->right);
        if(isSymmetricLeft ==false) return false;
        bool isSymmetricRight = isSymmetricHelper(leftNode->right, rightNode->left);
        if(isSymmetricRight == false) return false;


        return isSymmetricLeft && isSymmetricRight;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        return isSymmetricHelper(root->left, root->right);
    }
};

int main() {
    Solution sol;
    return 0;
}