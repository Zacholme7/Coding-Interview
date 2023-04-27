// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy
// Date solved: April 27, 2023
/*
Solution
This is just the iterative version of a preorder traversal. All we need to do is to maintain a stack to 
keep track of the nodes. We know that preorder is root left right. At each iteration, we want to print the root,
then add the children to the stack. The key is that we want to iterate down the left side first, so we need to
add the right side to the stack first. This will make it so that the left side is on the top of the stack
first and therefore it can be popped from the top of the stack. At each iteration we just add the nodes value 
to a vector and return it at the end
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            TreeNode *currRoot = nodes.top();
            nodes.pop();
            res.push_back(currRoot->val);
            if(currRoot->right) {
                nodes.push(currRoot->right);
            }
            if(currRoot->left) {
                nodes.push(currRoot->left);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}