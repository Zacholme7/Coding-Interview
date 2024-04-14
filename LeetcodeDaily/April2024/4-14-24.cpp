// link: https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14
// difficulty: easy
// date solved: april 14, 2024

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
    void helper(TreeNode* node, int &res, bool isLeft) {
        if (node == nullptr) {
            return;
        }

        // Check if it's a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            // If it's a left leaf, add its value
            if (isLeft) {
                res += node->val;
            }
        }

        // Recur for the left and right child
        helper(node->left, res, true);  // Pass true as it's a left child
        helper(node->right, res, false);  // Pass false as it's a right child
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        helper(root, res, false);  // Start with false as root is not a left child
        return res;
    }
};

