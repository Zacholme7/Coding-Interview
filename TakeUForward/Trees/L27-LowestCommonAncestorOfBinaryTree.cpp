// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty: Medium 
// Date solved: May 24, 2023
/*
Solution: 
Pretty simple problem. We want to find the lowest common ancestor of p and q. we can do this by returning the actual node p or q in the tree if 
we find it, else return null. If they are in the same subtree, we know that we will find one node on one side and null on the other, so we can return 
the lowest common acnestor. If there is a node on both sides, that means one of p and q was found in both sides of the tree, so that the root is the LCA. 
Otherwise, it was as described above, we will find both nodes in one of the subtrees and as we are returning, we keep retuning that node.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left && right) {
            return root;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}