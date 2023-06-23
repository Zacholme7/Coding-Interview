// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// Difficulty: Medium
// Date solved: June 23, 2023
// Time:  O(n)
// Space:  O(1)
/*
Solution: 
This is a very easy problem that is just a basic binary tree insertion. For this we always want to insert as a leaf
node. So we just compare the node to the current value, if it is greater than the current root, we want to move right.
We check if right is null, and if it is we insert the node, else we move to the right. The opposite is true for the left
hand side when we want to move smaller.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *curr = root;

        while(curr) {
            if(curr->val < val) {
                if(curr->right == NULL) {
                    curr->right = new TreeNode(val);
                    break;
                } else {
                    curr = curr->right;
                }
            } else {
                if(curr->left == NULL) {
                    curr->left = new TreeNode(val);
                    break;
                } else {
                    curr = curr->left;
                }
            }
        }
        return root;
        
    }
};

int main() {
    Solution sol;
    return 0;
}