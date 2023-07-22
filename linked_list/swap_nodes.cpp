#include <asm-generic/errno.h>
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
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
  ListNode *swapNodes(ListNode *head, int k) {

    if (head->next == nullptr) {
      return head;
    }

    if (head->next->next == nullptr) {
      ListNode *new_head = head->next;
      new_head->next = head;
      head->next = nullptr;
      return new_head;
    }

    ListNode *temp = head;
    int size = 0;
    while (temp != nullptr) {

      size++;
      temp = temp->next;
    }

    if (size % 2 != 0 and k == size / 2) {
      return head;
      //* swap the same node
    }

    k = (k > (size / 2)) ? (size - k) : k;

    return nullptr;
  }
};