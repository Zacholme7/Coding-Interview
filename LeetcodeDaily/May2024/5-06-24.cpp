// link: https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06
// difficulty: medium
// date solved: may 6, 2024

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    curr = prev->next;
    prev->next = nullptr;
    while (curr != nullptr) {
      ListNode *temp = curr->next;
      if (curr->val >= prev->val) {
        curr->next = prev;
        prev = curr;
      }
      curr = temp;
    }

    return prev;
  }
};
