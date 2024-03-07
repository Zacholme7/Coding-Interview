// link:
// https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
// difficulty: easy
// date solved: march 6, 2024

#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast and fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        return true;
      }
    } 

    return false;
  }
};
