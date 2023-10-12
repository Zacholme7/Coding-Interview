// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Difficulty: Medium 
// Date solved: June 8, 2023
/*
Solution: 
Again this problem is pretty simple, but it just requires some funky indexing to solve. We make a map 
to track the inorder traversal so that we can get the index. We then call a recursive builder function.
We know that our root will be at the end of the postorder, then we want to find the appropriate values
in the inorder and postorder to pass to the next iteration of the builder so that the only nodes in each 
side are the ones that correspond to that subtree
*/

#include <vector>
#include <iostream>
#include <map>
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
    TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int nodeIdx = inMap[postorder[postEnd]];
        root->left = buildTree(inorder, inStart, nodeIdx - 1, 
        postorder, postStart, postStart + nodeIdx - inStart - 1, inMap);
        root->right = buildTree(inorder, nodeIdx + 1, inEnd, 
        postorder, postStart + nodeIdx - inStart, postEnd - 1, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) {
            return NULL;
        }
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildTree(inorder, 0, inorder.size() - 1, 
        postorder, 0, postorder.size() - 1, inMap);
        return root;
    }
};


int main() {
    Solution sol;
    return 0;
}