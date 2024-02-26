// link:
// https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
// difficulty: easy
// date solved: february 26, 2024

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // if they are both nullpointers, we have reached base case
    if (p == nullptr and q == nullptr) {
      return true;
    }

    // if just one of them are a null pointer, then they are not equal
    if (p == nullptr or q == nullptr) {
      return false;
    }

    // compare the values
    if (p->val != q->val) {
      return false;
    }

    return isSameTree(p->right, q->right) and isSameTree(p->left, q->left);
  }
};

int main() {}
