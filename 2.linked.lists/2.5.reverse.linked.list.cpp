/**
 * @file 2.5.reverse.linked.list
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday September 20 2020
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
  ListNode *reverseList(ListNode *h) {
    ListNode *p = 0;

    while (h) {
      ListNode *tmp = h->next;
      h->next = p;
      p = h;
      h = tmp;
    }

    return p;
  }
};
