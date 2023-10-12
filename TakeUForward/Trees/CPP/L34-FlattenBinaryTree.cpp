// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty: Meidum
// Date solved: June 18, 2023
// Time: O(N)
// Space: O(N)
/*
Solution: 
This problem is deceptively difficult. My intuative solution is stack based. We add the right subtree to the stack
add the left subtree to the stack. and then set the right pointer to point to whatever is on the stop of the stack, a
and the left pointer to NULL since we just care about what the right is pointing too. 
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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *curr = st.top(); st.pop();
            if(curr->right) {
                st.push(curr->right);
            }
            if(curr->left) {
                st.push(curr->left);
            }
            curr->left = NULL;
            if(!st.empty()) {
                curr->right = st.top();
            }
        }
    }
};

int main() {
    Solution sol;
    return 0;
}