// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty: Easy
// Date solved: April 28, 2023
/*
Solution
For the iterative version, we can mimic the call stack of the recursive version. We want to go as far left as possible, take the 
root, then move one to the right. So we have our stack and we want to keep looping untill the stack is empty. We have a node that
tracks where we are and we have an if condition that will take us all the way down the left and add the nodes to the stack.
If we can not go down the left anymore, we want to take the top of the stack, add it to the result since this will be out root print
then move to the right and start over again
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *node = root;
        stack<TreeNode*> st;
        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if(st.empty() == true){
                    break;
                }
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}