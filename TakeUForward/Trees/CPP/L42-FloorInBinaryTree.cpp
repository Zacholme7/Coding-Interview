// Link: https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
// Difficulty: Easy
// Date solved: June 22, 2023
// Time:  O(n)
// Space:  O(1)
/*
Solution: 
Same as the last problem. We want to find the number that is smaller than x but the largest one int he tree.
If the current node is bigger than X, then we want to go to the left for smaller values. If the node is smaller than
x, then we know it is a potential floor, set it at the new floor, and then move to the right for bigger values.
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
    int findFloor(TreeNode *node, int x) {
        int floor = -1;
        while(node) {
            if(node->val == x) {
                return node->val;
            }
            if(node->val < x) {
                floor = node->val;
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return floor;
    }
};

int main() {
    Solution sol;
    return 0;
}