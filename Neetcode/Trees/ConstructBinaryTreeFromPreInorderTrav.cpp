// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Difficulty: Medium 
// Date solved: June 8, 2023
/*
Solution: 
So the idea behind this is simple but the implementation is pretty tricky. you have to correclty understand how to partition the inorder and preorder arrays
so that each left and right recursive call has the correct elements. Initially, we can make a nodemap that will map all of the inorder elements to an index 
so that we can easily find what index they are at to partition it. We then call a build function with the map, a preorder start and end, and and inorder start and end, and 
each vector respectivley. In the buildtree call, if the start is ever past the end, then we know that we are done. We create the root with the first node in the 
preorder array, which we can access with the prestart, since we know preorder will hit the root first. Then we make the recursive call for the right and left subtrees.
This is where we have to figure out what indexes to map. So for the left call, we know that we want all the nodes in the LEFT side of the inorder traversal witht he current root.
we know we can get the current index through our map so the start will be the current instart and the inEnd will be the current root index - 1. The opposiute is for the right
subtree, the instart will be the current roto index + 1 to inend. for the preorder, we know that for the left, we just want to take the following number of nodes that are 
to the left in the inorder, so we can calculate this by taking the root index - the start of the inorder. Then in our call, we want to skip the current preStart, so the start will
be preStart + 1 and we want to go to the start + the number of elemens to the left. for the right call, we want to start where we left off in the left call + 1 and go to the end.
This will construct the left and right trees and we add these onto the root and return the root
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
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> nodeMap) {
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = nodeMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, nodeMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, nodeMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> nodeMap;
        for(int i = 0; i < inorder.size(); i++) {
            nodeMap[inorder[i]] = i;
        }

        TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, nodeMap);
        return root;
    }
};


int main() {
    Solution sol;
    return 0;
}