/**
 * @file 2.6.merge.k.sorted.lists
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
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *r = new ListNode(0), *h = r;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        r->next = new ListNode(l1->val);
        l1 = l1->next;
        if (!l1) r->next->next = l2;
      } else {
        r->next = new ListNode(l2->val);
        l2 = l2->next;
        if (!l2) r->next->next = l1;
      }
      r = r->next;
    }

    return h->next;
  }

 public:
  ListNode* mergeKLists(vector<ListNode*>& l) {
    if(l.empty()) return 0;
    int n = l.size();

    while (n != 1) {
      int j = 0;
      for (int i = 0; i + 1 < n; i += 2) {
        l[j++] = mergeTwoLists(l[i], l[i + 1]);
      }
      if (n & 1) l[j++] = l[n - 1];
      n = j;
    }

    return l[0];
  }
};
