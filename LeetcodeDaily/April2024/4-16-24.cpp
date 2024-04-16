// link: https://leetcode.com/problems/add-one-row-to-tree/?envType=daily-question&envId=2024-04-16
// difficulty: medium
// date solved: april 16, 2024
// solution writeup: just do a standard traversal, when you reach correct level in the tree, follow the basic
// logic to save the left and right nodes, insert new ones, and then update their pointers. Make sure to handle
// edge case where you update the tree when depth is 1.

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void helper(TreeNode *node, int currDepth, int targetDepth, int val) {
    // base case
    if (node == nullptr) {
      return;
    }

    // add the nodes in
    if (currDepth == targetDepth - 1) {
      TreeNode *leftChild = node->left;
      TreeNode *rightChild = node->right;

      node->left = new TreeNode(val);
      node->left->left = leftChild;
      node->right = new TreeNode(val);
      node->right->right = rightChild;
      return;
    }

    // recurse
    helper(node->left, currDepth + 1, targetDepth, val);
    helper(node->right, currDepth + 1, targetDepth, val);
  }


  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, nullptr);
    }
    helper(root, 1, depth, val);
    return root;
  }
};
