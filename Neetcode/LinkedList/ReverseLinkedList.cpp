// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy
// Date Solved: May 8, 2023
/*
Solution
An easy must know problem. The key is to just adjust pointers correctly and re point everything to the previous. We start off by saving the 
head next to a temp since we want to adjust the pointer to this node and dont want to lost it. We can then set the head next to the prev which is initally 
a null. We then set the prev to the head and the head to the temp which is the next node in the list. At the end the head will be null and this is our terminating
and the prev will point to the new head in the list so we return that.
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};


int main() {
    Solution sol;
    return 0;
}