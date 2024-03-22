// link: https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22
// difficulty: easy
// date solved: march 22, 2024
// solution writeup: for my solution I just assigned all the values to a vector
// and iterated through from the left and the right to look if they are the all
// the same. Very simple. Could also find middle, reverse second half, then
// iterate through both
#include <vector>
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
  bool isPalindrome(ListNode *head) {
    vector<int> values;

    while (head != nullptr) {
      values.push_back(head->val);
      head = head->next;
    }

    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
      if (values[left] != values[right]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
