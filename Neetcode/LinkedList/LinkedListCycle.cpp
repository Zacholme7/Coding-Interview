// Link: https://leetcode.com/problems/linked-list-cycle/
// Difficulty: Easy
// Date Solved: May 29, 2023
/*
Solution
Very simple basic linked list problem, just want to check if the linked list has a cycle. This can be accomlished with a fast and a slow pointer.
On each iteration, we check to make sure that fast is valid and so is fast->next. If either of these are not, we know that the list terminates. Otherwise,
we move slow one forward and we move fast two forward. We can then check to see if they point to the same node and return true if they do.
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
        
    }
};

int main() {
    Solution sol;
    return 0;
}