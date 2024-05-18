// link: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18
// difficulty: medium
// date solved: may 18, 2024
#include <cmath>

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
  int moves = 0;
  int helper(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftExcess = helper(root->left);
    int rightExcess = helper(root->right);

    moves += abs(leftExcess) + abs(rightExcess);
    return root->val + leftExcess + rightExcess - 1;


  }
  int distributeCoins(TreeNode *root) {
    helper(root);
    return moves;
  }
};
