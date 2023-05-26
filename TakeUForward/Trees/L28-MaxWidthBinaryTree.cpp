// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Difficulty: Medium 
// Date solved: May 25, 2023
/*
Solution: 
just index the tree
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, long>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++) {
                long curId = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if(i == 0)
                    first = curId;
                if(i == size - 1)
                    last = curId;
                if(node->left)
                    q.push({node->left, curId * 2 + 1});
                if(node->right)
                    q.push({node->right, curId * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}