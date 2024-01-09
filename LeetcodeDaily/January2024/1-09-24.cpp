// link: https://leetcode.com/problems/leaf-similar-trees/
// difficulty: easy
// date solved: january 9, 2024
#include <vector>

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
  void getLeafOrder(TreeNode *node, std::vector<int> &leafValues) {
    if (node == NULL) {
      return;
    }

    getLeafOrder(node->left, leafValues);
    if (node->left == NULL && node->right == NULL) {
      leafValues.push_back(node->val);
    }
    getLeafOrder(node->right, leafValues);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::vector<int> leafVal1, leafVal2;
    getLeafOrder(root1, leafVal1);
    getLeafOrder(root2, leafVal2);

    return leafVal1 == leafVal2;
  }

};
