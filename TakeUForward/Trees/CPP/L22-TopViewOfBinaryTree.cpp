// Link: No link
// Difficulty: ???
// Date solved: May 17, 2023
/*
Solution: 
Utilize the same idea of tracking the col as the last problem. Do a level order traversal and if its the first time we see a call, add it to the map. Add all of the 
elemetns of the map to a vector at the end and return. 
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
    vector<int> topView(TreeNode *root) {
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
                if(mpp.find(line) == mpp.end()) {
                    mpp[line] = node->val;
                }
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