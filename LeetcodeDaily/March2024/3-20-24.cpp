// link: https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20
// difficulty: medium
// date solved: march 20, 2024

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *dummy = new ListNode(0);
    dummy->next = list1;
    ListNode *prevA = dummy;
    ListNode *afterB = nullptr;

    for (int i = 0; i < a; i++) {
      prevA = prevA->next;
    }

    afterB = prevA;

    for (int i = 0; i < b - a + 2; i++) {
      afterB = afterB->next;
    }

    ListNode *tailList2 = list2;
    while (tailList2->next != nullptr) {
      tailList2 = tailList2->next;
    }

    tailList2->next = afterB;
    prevA->next = list2;

    ListNode *ret = dummy->next;
    delete dummy;
    return ret;
  }
};
