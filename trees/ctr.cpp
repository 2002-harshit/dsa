#include <climits>
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node() : left(nullptr), right(nullptr) {}
  Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree {
  Node *root = nullptr;

  void create(vector<int> &vec) {

    Node *root = new Node(vec[0]);
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    int idx = 0;

    while (!st.empty()) {
      pair<Node *, int> &top = st.top();

      idx++;
      if (top.second == 1) {
        if (vec[idx] != INT_MIN) {

          top.first->left = new Node(vec[idx]);

          st.push({top.first->left, 1});
        } else {
          top.first->left = nullptr;
        }
        top.second++;
      } else if (top.second == 2) {
        if (vec[idx] != INT_MIN) {

          top.first->right = new Node(vec[idx]);

          st.push({top.first->right, 1});
        } else {
          top.first->right = nullptr;
        }
        top.second++;
      } else {
        st.pop();
      }
    }
  }
};

int main() {
  vector<int> vec = {1, 2, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN};
  return 0;
}