/**
 * @file 2.3.reverse.nodes.in.k.group
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
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *r, int k) {
    int n = 0;
    ListNode *h = r, *rr = 0;
    while (h) {
      ++n;
      if (n == k) rr = h;
      h = h->next;
    }

    h = r;

    ListNode *t1 = 0, *t2;
    while (n >= k) {
      ListNode *p = 0;
      for (int i = 0; i < k; ++i) {
        if (!i) t2 = h;
        ListNode *tmp = h->next;
        h->next = p;
        p = h;
        h = tmp;
      }
      // p = rhead
      if (t1) t1->next = p;
      t1 = t2;
      n -= k;
    }

    if (h) t2->next = h;

    return rr;
  }
};
