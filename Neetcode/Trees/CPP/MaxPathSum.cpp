// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Difficulty: Hard
// Date solved: May 11, 2023
/*
Solution: 
I dont think this should be a hard problem. Anyways, like many others we have seen so far this problem is just a twist on the height of a binary
tree problem. We want to find the max path sum, this can be similar to the diameter where the max path can be a subtree. Another part of this is
that we have to deal with negative numbers. We just have a helper function with a reference to a max var to track the max. We recurse until we 
hit a null and return 0. Initially, we want to get the sum of the left and the right sides, and want to see what the max path through the root is. 
You can do this by checking the max of the curr max, left + root, right + root, root, and left + root + right. This is to deal with negative numbers
just through the max function. What you can do instead is just to ignore the negatives to begin with and put zero in there place. That makes it so we just have
to check left + root + right. So if a left or a right side returns a negative number, we just want zero instead and this logic can be found where we get the 
sums of the sides and take that and the max with zero. This makes it so we dont have to deal with negatives. As the return, we just want to return the max of left + root
or right + root so that we have the current max path for the node above.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    int maxPathHelper(TreeNode *root, int &maxSum) {
        if(root == NULL) {
            return 0;
        }
        int leftSum = max(0, maxPathHelper(root->left, maxSum));
        int rightSum = max(0, maxPathHelper(root->right, maxSum));
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; 
        maxPathHelper(root, maxSum);
        return maxSum;
    }
};

int main() {
    Solution sol;
    return 0;
}