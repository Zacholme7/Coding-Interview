// link: https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16
// difficulty: easy
// date solved: may 16, 2024

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

  bool isLeaf(TreeNode *node) {
    return node->left == nullptr and node->right == nullptr;
  }


  bool evaluateTree(TreeNode *root) {
    if (isLeaf(root)) {
      return root->val;
    }

    bool leftEval = evaluateTree(root->left);
    bool rightEval = evaluateTree(root->right);

    if (root->val == 2) {
      return leftEval or rightEval;
    } else {
      return leftEval and rightEval;
    }
  }
};
