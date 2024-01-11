// link:
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
// difficulty: medium
// date solved: january 11, 2024

#include <algorithm>
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
  int maxAncestorDiff(TreeNode *root, int mn = 10000, int mx = 0) {
    if (root == nullptr) {
      return mx - mn;
    }

    mx = std::max(mx, root->val);
    mn = std::min(mn, root->val);

    return std::max(maxAncestorDiff(root->left, mn, mx), maxAncestorDiff(root->right, mn, mx));
  }
};

int main() { return 0; }
