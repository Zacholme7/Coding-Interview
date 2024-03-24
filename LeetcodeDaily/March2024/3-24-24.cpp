// link: https://leetcode.com/problems/validate-binary-search-tree/description/
// difficulty: medium
// date solved: march 24, 2024

#include <vector>
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
        void inorderTraversal(TreeNode *node, vector<int> &res) {
                if (node == nullptr) {
                        return;
                }

                inorderTraversal(node->left, res);
                res.push_back(node->val);
                inorderTraversal(node->right, res);
        }

    bool isValidBST(TreeNode* root) {
        vector<int> res{};
        inorderTraversal(root, res);

        for(int i = 1; i < res.size(); i++) {
                if (res[i] <= res[i-1]) {
                        return false;
                }
        }
        return true;
    }
};