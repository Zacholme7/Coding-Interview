// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Difficulty: Hard
// Date solved: May 16, 2023
/*
Solution: 
This is a hard problem I solved all on my own and it beats 100% of runtimes!!!! We want a vertical order tracersal. My idea was to use a map which will be used 
to track the column and then have a vector that will store the values. A map will make it so that the keys (cols) are sorted so I can easily loop through and add
them at the end. I then wanted to use a deque to track the level order iteration since we can sort a deque and not a queue. In the dequee, I store a pair of a pair 
which contains the treenode and a pair of the row and column. I start off with a standard level order traversal. The key part is the custom comparator function.
When we hit a level with the same row/col for two nodes, we want to stort these by value. This is what the custom comparator will do. So when we continue the level
order like normal, extract the elements, add the children with the correct row and col values updates. We also have to add the nodes value to the map with the key/col
At the end I just loop over the map and appeend each col vector to a resulting vector since we know it will be sored by key and that each interal vector will be in the correct order 
based off of the custom comparator function.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <deque>
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

    bool compare(const std::pair<TreeNode*, std::pair<int, int>>& left, const std::pair<TreeNode*, std::pair<int, int>>& right) {
        // Compare the second element of the inner pair in ascending order
        if (left.second.second < right.second.second) {
            return true;
        } else if (left.second.second > right.second.second) {
            return false;
        }
        // If the second element of the inner pair is the same, compare the first element of the outer pair in ascending order
        return left.first->val < right.first->val;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> colMp; // int = col number, vector = values in that col
        vector<vector<int>> res; // resulting vector
        if(root == NULL) {
            return res;
        }
        deque<pair<TreeNode*, pair<int, int>>> q; // <Node, <row, col>>
        q.push_back({root, {0, 0}});
        while(!q.empty()) {
            int qSz = q.size();
            sort(q.begin(), q.end(), compare);
            for(int i = 0; i < qSz; i++) {
                auto currPair = q.front();
                q.pop_front();
                // extract the elements
                TreeNode *node = currPair.first;
                int row = currPair.second.first;
                int col = currPair.second.second;

                // add into the map
                colMp[col].push_back(node->val);

                // add the new nodes in
                if(node->left) q.push_back({node->left, {row + 1, col - 1}});
                if(node->right) q.push_back({node->right, {row + 1, col + 1}});
            }
        }

        for(auto &element: colMp) {
            vector<int> colVec = element.second;
            res.push_back(colVec);
        }
        return res;
    }
};


int main() {
    Solution sol;
    return 0;
}