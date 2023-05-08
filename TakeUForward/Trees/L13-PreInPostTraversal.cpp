// Link: no leetcode link
// Difficulty: no leetcode problem
// Date solved: May 8, 2023
/*
Solution
this combines a preorder, inorder, and postorder traversal into one and only uses one stack. The key is to keep a number that tracks which stage of the 
traversal each node is at. If a node has a tracker of 1, we know it is in the preorder stage and is the first time it has been seen, so we add it to the preorder
list, readd it to the stack, and add its left child. If a node has a tracker of 2, we know that this is the second time it has been seen so we add it to the inorder list, 
add it back to the stack, and add its right child to the stack too. If a node has a tracker of 3, we know that this it the thrid time it has been seen so we add it to the postorder list.
We know that root comes last in the postorder and this is third time we have seen the node so we can be confidnent that this ist he last time we need to visit it.
*/


#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> prepostinorderTraversal(TreeNode *root) {
        vector<int> preorder;
        vector<int> inorder;
        vector<int> postorder;
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        pair<TreeNode*, int> nodePair{root, 1};
        stack<pair<TreeNode*, int>> st;
        st.push(nodePair);
        while(!st.empty()) {
            pair<TreeNode*, int> currPair = st.top();
            st.pop();
            if(currPair.second == 1) {
                preorder.push_back(currPair.first->val);
                currPair.second++;
                st.push(currPair);
                if(currPair.first->left){
                    st.push({currPair.first->left, 1});
                }
            } else if (currPair.second == 2) {
                inorder.push_back(currPair.first->val);
                currPair.second++;
                st.push(currPair);
                if(currPair.first->right) {
                    st.push({currPair.first->right, 1});
                }
            } else {
                postorder.push_back(currPair.first->val);
            }
        }
        res.push_back(preorder);
        res.push_back(inorder);
        res.push_back(postorder);
        return res;
    }
};


int main() {
    Solution sol;
    return 0;
}