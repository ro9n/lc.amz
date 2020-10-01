/**
 * @file 2.1.add.two.nums
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0; ListNode *r = new ListNode(0), *h = r;
    while(l1 || l2 || c) {
      int x = l1 ? l1->val : 0, y = l2 ? l2->val : 0;
      int s = x + y + c;
      if (s >= 10) c = 1, s -= 10; else c = 0;
      h->next = new ListNode(s); h = h->next;
      if (l1) l1 = l1->next; if(l2) l2 = l2->next;
    }

    return r->next;
  }
};

int main() {
  auto s = new Solution();
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(5); l2->next = new ListNode(6); l2->next->next = new ListNode(4);

  ListNode *l3 = s->addTwoNumbers(l1, l2);

  while(l3) { cerr << l3->val; l3 = l3->next; }
  return 0;
}