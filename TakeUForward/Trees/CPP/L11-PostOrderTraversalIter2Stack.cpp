// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// Difficulty: Easy
// Date solved: May 6, 2023
/*
Solution
This is just a postorder traversal but it is using two stacks. One stack will be used for the iteration, and the other will be used 
to store the result. We know the iteration for a postorder is left right root. So we will do that. In the main stack we will keep track of
our nodes. At each iteration we will pop off the top node, put it on our printed stack, and then add the left child and then the right child.
This is backwards since we want to add the right children to the print stack first since the left childen should be printed first. So we will add all 
of the right side, then add all of the left side, then reuturn the values from the second stack.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode *node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) {
                st1.push(node->left);
            }
            if(node->right) {
                st1.push(node->right);
            }
        }

        while(!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};


int main() {
    Solution sol;
    return 0;
}