// Link: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
// Difficulty: Easy
// Date solved: June 21, 2023
// Time:  O(n)
// Space:  O(1)
/*
Solution: 
Simple problem that took me way to long to wrap my head around. If the current node is our value, then we have found it 
and can just return that. If the current node is greater than out value, we know that it is a potential ceil so we set it 
and then we move to the left since we want smaller numbers. If our current node is bigger than our value, we know that it cannot
be a potential ceil and we move right because we want larger values
*/

#include <iostream>
#include <vector>
#include <stack>
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
    int findCeil(TreeNode *node, int x) {
        int ceil = -1;
        while(node) {
            if(node->val == x) {
                return node->val;
            }
            if(node->val >= x) {
                ceil = node->val;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return ceil;
    }
};

int main() {
    Solution sol;
    return 0;
}