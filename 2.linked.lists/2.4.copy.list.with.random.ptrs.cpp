/**
 * @file 2.4.copy.list.with.random.ptrs
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday September 20 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* r) {
    Node *h = r, *cr = new Node(0), *ch = cr;
    unordered_map<Node*, Node*> m;

    while (h) {
      m[h] = new Node(h->val);
      ch->next = m[h];
      ch = ch->next;
      h = h->next;
    }

    h = r, ch = cr;
    while (h) {
      ch->next->random = m[h->random];
      h = h->next;
      ch = ch->next;
    }

    return cr->next;
  }
};
