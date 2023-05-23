// Link: No link
// Difficulty: ????
// Date solved: May 23, 2023
/*
Solution: 
This is just an recursive preorder solution where are are maintaining a path. When we see node, we add it to the result. We then go down the left and the right, each time adding the node to our output.
When we hit a leaf node that is not on the path, we start returning and popping off nodes. If we find a path where we have the node after adding to the vector, we return true. We can keep checking if 
the left or the right paht returned true and just keep returning true to work our way back up the tree untill we can return then return res which will have the path that we want. 
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

    bool findPath(TreeNode *node, vector<int> &res, int val) {
        if(node == NULL) {
            return false;
        }
        res.push_back(node->val);
        if(node->val == val) {
            return true;
        }

        if(findPath(node->left, res, val) || findPath(node->right, res, val)) {
            return true;
        }

        res.pop_back();
        return false;

    }
    vector<int> rootToNodePath(TreeNode *root, int val) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        findPath(root, res, val);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}