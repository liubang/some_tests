#include <gtest/gtest.h>
#include "includes/list.h"

namespace {
class Solution {
 public:
  leetcode::list::ListNode* reverseList(leetcode::list::ListNode* head) {
    if (!head) {
      return nullptr;
    }
    leetcode::list::ListNode* pre = nullptr;
    leetcode::list::ListNode* cur = head;
    while (cur) {
      leetcode::list::ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};
} // namespace

TEST(Leetcode, reverse_linked_list) {
  Solution s;
  leetcode::list::ListNode* head = leetcode::list::create({1, 2, 3, 4, 5});
  leetcode::list::ListNode* ret = s.reverseList(head);
  std::vector<int> exp = {5, 4, 3, 2, 1};
  int i = 0;
  leetcode::list::ListNode* cur = ret;
  while (cur) {
    EXPECT_EQ(exp[i++], cur->val);
    cur = cur->next;
  }
  destroy(ret);
}