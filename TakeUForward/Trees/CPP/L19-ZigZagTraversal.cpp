// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty: Medium
// Date solved: May 14, 2023
/*
Solution: 
this is just a twist on the level order traversal. The only different is that we dont know if we should be going left to rith or right to left at each level.
We can use a boolean to track this and we should inverse it at each new level iteration. We just declare our level vector to have the correct number of elements
from the start, and then we can calulate the index as i if we are going left to rith or size - i - 1 if we are going right to left. Just put the value into the correct
spot and do everything else like it is a level order traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                q.pop();

                int index = (leftToRight) ? i : (size - 1 - i);

                level[index] = tmp->val;
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }

};

int main() {
    Solution sol;
    return 0;
}