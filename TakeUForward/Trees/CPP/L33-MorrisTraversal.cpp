// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Difficulty: Hard 
// Date solved: June 14, 2023
// Time: O(n)
// Space: O(1)
/*
Solution: 
Does not consume extra space
1st case: if left is null, print current node and go right
2nd case: before going left, make right most node on left subtree connected to current node, then go left
3rd case: if thread is already pointed to current node, then remove the thread
easy one line change to make inorder into preorder
what are are doing is that we are threading the rightmost child to the root.
*/

#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr -> left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                preorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr -> left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }

};



int main() {
    Solution sol;
    return 0;

}