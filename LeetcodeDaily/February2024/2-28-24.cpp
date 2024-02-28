// link:
// https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28
// difficulty: medium
// date solved: february 28, 2024

#include <queue>
using namespace std;

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
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q{};
    q.push(root);
    TreeNode* res;

    while (q.size() > 0) {
      int qLen = q.size();
      res = q.front();
      for (int i = 0; i < qLen; i++) {
        TreeNode *currNode = q.front();
        q.pop();

        if (currNode->left) {
          q.push(currNode->left);
        }

        if (currNode->right) {
          q.push(currNode->right);
        }
      }

    }

    return res->val;
  }
};
