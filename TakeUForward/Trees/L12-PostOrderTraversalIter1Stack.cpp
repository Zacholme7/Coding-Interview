// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// Difficulty: Easy
// Date solved: May 7, 2023
/*
Solution
This is a big of a tricky traversal to do iteratively while be optimal. The key concept is taht we want to go all the way left until we cant
anymore, go one to the right, and then go all the way left again. Contiue this until you are at a left node. Work back up the path, and then go down
the next unxplored rigth->left path. So that is what we do. We have a node to track where were are and we go down the left as far as we can by
pushing the node onto the stack and then moving to the right. When curr is null meaning we have gone as far as we can, we take the node off of the 
top of the stack which was the more recently visited node and go to its right. If this node is also null, then we are at a left, otherwise, we set this to 
the current and go down the left again. If this node is a leaf, we want to take it off the stack, add it to our array, and backtrack as far as we can.
This is done in the while loop which will backtrack while there are still nodes in the stack and while the temportaty node is equal to the right of the top, meaning 
we can still go back farther. we just add these values to the resulting array and then at the end we can just return the array. 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode *temp = st.top()->right;
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        res.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    return 0;
}