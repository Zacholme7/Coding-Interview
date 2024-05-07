# link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07
# difficulty: medium
# date solved: may 7, 2024

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def doubleIt(self, head):
        nums = []
        tmp = head
        while tmp is not None:
            nums.append(str(tmp.val))
            tmp = tmp.next

        number_str = "".join(nums)

        doubled_number_str = str(int(number_str) * 2)

        head = ListNode(int(str(doubled_number_str)[0]))
        tmp = head
        for digit in doubled_number_str[1:]:
            tmp.next = ListNode(int(digit))
            tmp = tmp.next

        return head
