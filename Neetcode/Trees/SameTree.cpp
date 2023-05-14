// Link: https://leetcode.com/problems/same-tree/
// Difficulty: Easy
// Date solved: May 12, 2023
/*
Solution: 
This problem is just checking if two binary trees are the exact same. Our base case is when BOTH p and q are null which means that we can return true.
We also have to check if either p or q are null because if one is null and one is not, then the would pass the first check and we want to return false since
these are clearly not the same. If both nodes are not null, we want to then check the value and return false if they are not the same. We do this for the left and 
the right side and then return these two values AND
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else if (p->val != q->val) {
            return false;
        }

        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);

        return isSameLeft && isSameRight;
    }
};

int main() {
    Solution sol;
    return 0;
}