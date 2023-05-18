// Link: No link
// Difficulty: ???
// Date solved: May 18, 2023
/*
Solution: 
Literally the exact same solution as top view with one line adjusted. You want to do a level order traversal but instead of just adding a node the first time we see
the column, we add it every time we see the column. This will make it so that the last time we see a column that node is the one that is added to the map possibly overwriting
a previous column we have seen
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
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
    vector<int> bottomView(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                TreeNode *node = curr.first;
                int line = curr.second;
                mpp[line] = node->val;
                if(node->left) {
                    q.push({node->left, line-1});
                }
                if(node->right) {
                    q.push({node->left, line+1});
                }
            }
        }

        for(auto it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}