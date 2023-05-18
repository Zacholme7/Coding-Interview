// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
// Date solved: May 18, 2023
/*
Solution: 
Listed as a medium but this is a very easy problem. Its just a level order traversal with a twist. We know that we want the node that is the farthest to the right on any 
given level. What do we know about a level order traversal? Each iteration will have a queue with all the nodes of a current level. All we have to do is add either
the back or front nodes value to an answer vetor on each iteration, depending on if you add the left or the right node first, then just return the vector at the end.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            ans.push_back(q.front()->val);
            for(int i = 0; i < sz; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->right) {
                    q.push(curr->right);
                }
                if(curr->left) {
                    q.push(curr->left);
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}