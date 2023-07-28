#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  vector<Node *> children;
};

class GenericTree {

public:
  Node *root = nullptr;
  Node *predecessor = nullptr;
  Node *successor = nullptr;
  Node *maxNode = nullptr;
  int maxSum = INT_MIN;
  int dia = INT_MIN;

  void create(vector<int> &vec) {
    stack<Node *> st;

    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == -1) {
        st.pop();
      } else {
        Node *new_node = new Node();
        new_node->data = vec[i];
        if (st.empty()) {
          this->root = new_node;
        } else {

          (st.top())->children.push_back(new_node);
        }
        st.push(new_node);
      }
    }
  }

  int size(Node *root) {
    if (root->children.size() == 0) {
      return 1;
    }

    int childSum = 0;

    for (int i = 0; i < (root->children.size()); i++) {
      childSum += size(root->children[i]);
    }

    return childSum + 1;
  }

  int max_node(Node *root) {
    if (root->children.size() == 0) {
      return root->data;
    }

    int max_val = INT_MIN;

    for (int i = 0; i < root->children.size(); i++) {
      max_val = max(max_val, max_node(root->children[i]));
    }

    return max(max_val, root->data);
  }

  int height(Node *root) {
    if (root->children.size() == 0) {
      return 0;
    }

    int max_depth = INT_MIN;

    for (int i = 0; i < root->children.size(); i++) {
      max_depth = max(max_depth, height(root->children[i]));
    }

    return max_depth + 1;
  }

  void pre_pro_traverse(Node *root) {
    cout << "Node Pre " << root->data << endl;

    for (int i = 0; i < root->children.size(); i++) {
      cout << "Edge pre " << root->data << "--" << root->children[i]->data
           << endl;
      pre_pro_traverse(root->children[i]);
      cout << "Edge post " << root->data << "--" << root->children[i]->data
           << endl;
    }

    cout << "Node Post " << root->data << endl;
  }

  void level_order(Node *root) {
    queue<Node *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      Node *front = nodes.front();
      nodes.pop();
      cout << front->data << " ";

      for (Node *&child : front->children) {
        nodes.push(child);
      }
    }
  }

  void level_order_line_wise(Node *root) {
    deque<Node *> parent;
    deque<Node *> bachhe;
    parent.push_back(root);

    while (!parent.empty()) {
      Node *front = parent.front();
      cout << front->data << " ";
      parent.pop_front();

      for (Node *&child : front->children) {
        bachhe.push_back(child);
      }

      if (parent.empty()) {
        parent = bachhe;
        bachhe.clear();
        cout << endl;
      }
    }
  }

  void level_order_line_wise_zig_zag(Node *root) {
    deque<Node *> parent;
    deque<Node *> bachhe;
    parent.push_back(root);
    int level = 1;

    while (!parent.empty()) {
      Node *top = parent.back();
      parent.pop_back();
      cout << top->data << " ";

      if (level % 2 != 0) {
        for (Node *&child : top->children) {
          bachhe.push_back(child);
        }
      } else {
        for (int i = top->children.size() - 1; i >= 0; i--) {
          bachhe.push_back(top->children[i]);
        }
      }

      if (parent.empty()) {
        parent = bachhe;
        bachhe.clear();
        level++;
        cout << endl;
      }
    }
  }

  void mirror(Node *root) {
    if (root->children.size() == 0) {
      return;
    }
    for (int i = 0; i < root->children.size(); i++) {
      mirror(root->children[i]);
    }

    reverse(root->children.begin(), root->children.end());
    //* bc fuddu sawaal tha, again try to remember the expectation, faith
    // approach, faith mere bachhon ko mirror karna aata hai, bas phir apne
    // bachhon ko reverse maaro, done!!
  }

  void level_order_line_wise_single_queue(Node *root) {
    //* again this apporach is also fairly basic, instead of 2 queues , it uses
    // a single queue with separator as nullptr to separate between different
    // levels;
    deque<Node *> list;
    list.push_back(root);
    list.push_back(nullptr);

    while (!list.empty()) {
      Node *front = list.front();
      list.pop_front();

      if (front != nullptr) {

        cout << front->data << " ";

        for (Node *&child : front->children) {
          list.push_back(child);
        }
      } else {
        cout << endl;
        if (!list.empty())
          list.push_back(nullptr);
      }
    }
  }

  void level_order_line_wise_using_count(Node *root) {
    deque<Node *> list;
    list.push_back(root);

    while (!list.empty()) {
      int count = list.size();

      for (int i = 0; i < count; i++) {
        Node *front = list.front();
        list.pop_front();
        cout << front->data << " ";

        for (Node *&child : front->children) {
          list.push_back(child);
        }
      }

      //* after the above for loop , one level will be completed
      cout << endl;
    }
  }

  void remove_leaves(Node *root) {
    for (int i = root->children.size() - 1; i >= 0; i--) {
      if (root->children[i]->children.size() == 0) {
        root->children.erase(root->children.begin() + i);
      }
    }

    // todo remove all the leaves of a given generic tree
    for (Node *&child : root->children) {
      remove_leaves(child);
    }
  }

  Node *getTail(Node *node) {
    while (node->children.size() != 0) {
      node = node->children[0];
    }

    return node;
  }

  void linearize(Node *root) {

    for (Node *&child : root->children) {
      linearize(child);
    }

    while (root->children.size() > 1) {
      Node *lastChild = root->children[root->children.size() - 1];
      root->children.erase(root->children.begin() + root->children.size() - 1);
      Node *secondLast = root->children[root->children.size() - 1];
      Node *tail = getTail(secondLast);
      tail->children.push_back(lastChild);
    }
  }

  Node *linearize_efficient(Node *root) {

    if (root->children.size() == 0) {
      return root;
    }
    //* now our faith is when we call this function, it will linearize and also
    // return the tail, so that we cann connect;

    Node *lastTail =
        linearize_efficient(root->children[root->children.size() -
                                           1]); //* you dont need its tail, but
                                                // you do need lineraization

    while (root->children.size() > 1) {
      Node *last =
          root->children[root->children.size() - 1]; //* get the last child
      root->children.erase(root->children.begin() + root->children.size() -
                           1); //* remove it from children
      Node *secondLastTail = linearize_efficient(
          root->children[root->children.size() -
                         1]);                   //* get second last childs tail
      secondLastTail->children.push_back(last); //* conect them
    }

    return lastTail;
  }

  bool find(Node *root, int val) {

    //* it is worth noticing in this question that the whole tree is not
    // travelled through, you may notice that once the element is found, you
    // return immediately and that answer propogates to the root.

    if (root->data == val) {
      return true;
    }

    // bool whetherChildrenHave = false;

    for (Node *&child : root->children) {
      bool whetherChildrenHave = find(child, val);
      if (whetherChildrenHave) {
        return true;
      }
    }

    return false;
  }

  vector<int> nodeToRootPath(Node *root, int val) {
    //* very similar to the find question
    vector<int> vec;
    if (root->data == val) {
      //* if you are the element, just push it to the path
      vec.push_back(root->data);
      return vec;
    }
    for (Node *&child : root->children) {
      vector<int> fromChild = nodeToRootPath(child, val);

      if (fromChild.size() > 0) {
        fromChild.push_back(root->data);
        return fromChild;
      }
    }

    //* if the element is not found, just return the empty path
    return vec;
  }

  vector<vector<int>> nodeToRootPathMultiple(Node *root, int val) {
    vector<vector<int>> ans;
    if (root->data == val) {
      vector<int> temp;
      temp.push_back(root->data);
      ans.push_back(temp);
      return ans;
    }

    for (Node *&child : root->children) {
      vector<vector<int>> ansFromChild = nodeToRootPathMultiple(child, val);
      if (ansFromChild.size() > 0) {
        for (vector<int> &path : ansFromChild) {
          path.push_back(root->data);
          ans.push_back(path);
        }
      }
    }

    return ans;
  }

  static bool areSimilar(Node *root1, Node *root2) {

    if (root1->children.size() != root2->children.size()) {
      return false;
    }

    for (int i = 0; i < root1->children.size(); i++) {
      bool result = areSimilar(root1->children[i], root2->children[i]);
      if (!result) {
        return result;
      }
    }

    return true;
  }

  static bool areTreesMirror(Node *root1, Node *root2) {
    //* this is only for mirrored structure
    if (root1->children.size() != root2->children.size()) {
      return false;
    }

    for (int i = 0; i < root1->children.size(); i++) {

      bool result = areTreesMirror(
          root1->children[i], root2->children[root2->children.size() - i - 1]);

      if (!result) {
        return result;
      }
    }

    return true;
  }

  static bool isSymmnetric(Node *root) { return areTreesMirror(root, root); }

  void successorPredecessor(Node *root, int data, int state) {

    if (state == 0) {
      if (root->data == data) {
        state = 1;
      } else {
        predecessor = root;
      }
    } else if (state == 1) {
      successor = root;
      state = 2;
      return;
    }

    for (Node *child : root->children) {
      if (state == 2) {
        return;
      }
      successorPredecessor(child, data, state);
    }
  }

  int getMaxSumSubtree(Node *root) {

    if (root->children.size() == 0) {
      return root->data;
    }
    int sum = 0;
    for (Node *&child : root->children) {
      int callRes = getMaxSumSubtree(child);

      if (callRes > this->maxSum) {
        this->maxSum = callRes;
        this->maxNode = child;
      }
      sum += callRes;
    }

    return sum + root->data;
  }

  int calcDiameterReturnDepth(Node *root) {

    int deepest = -1;
    int secondDeepest = -1;

    for (Node *&child : root->children) {

      int depth = calcDiameterReturnDepth(child);

      if (depth > deepest) {
        secondDeepest = deepest;
        deepest = depth;
      } else if (depth > secondDeepest) {
        secondDeepest = depth;
      }
    }

    if (deepest == -1 and secondDeepest == -1) {
      this->dia = max(this->dia, 0);
      return 0;
    } else if (deepest != -1 and secondDeepest == -1) {
      this->dia = max(this->dia, deepest + 1);
      return deepest + 1;
    } else if (deepest != -1 and secondDeepest != -1) {
      this->dia = max(this->dia, deepest + secondDeepest + 2);
      return deepest + secondDeepest + 2;
    }

    return 129;
  }
};

int main() {
  //   vector<int> vec = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
  vector<int> vec1 = {10,  20, 50, -1, 60, -1, -1, 30,  70, -1, 80, 110, -1,
                      120, -1, -1, 90, -1, -1, 40, 100, -1, -1, 50, -1,  -1};
  vector<int> vec2 = {10, 20, -50, -1, 60, -1, -1,   30, -70, -1,
                      80, -1, 90,  -1, -1, 40, -100, -1, -1,  -1};

  vector<int> vec = {10, 20,  50, -1, 60, -1, -1, 30, 70,  -1, 80, 1, 10,
                     -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
  //   vector<int> vec2 = {1,  2,  5,  -1, 6,  -1, -1, 3,  7,  -1, 8, 11, -1,
  //                       12, -1, -1, 9,  -1, -1, 4,  10, -1, -1, 5, -1, -1};
  GenericTree gt1;
  //   GenericTree gt2;
  gt1.create(vec);
  //   gt1.getMaxSumSubtree(gt1.root);
  //   cout << gt1.maxNode->data << "@" << gt1.maxSum;
  cout << gt1.calcDiameterReturnDepth(gt1.root);
  //   gt1.successorPredecessor(gt1.root, 120, 0);
  //   cout << gt1.predecessor->data;
  //   cout << gt1.successor->data;

  //   gt2.create(vec);
  //   cout << GenericTree::areSimilar(gt1.root, gt2.root);
  // cout << gt.size(gt.root);
  // cout << gt.max_node(gt.root);
  // cout << gt.height(gt.root);
  // gt.pre_pro_traverse(gt.root);
  // gt.level_order(gt.root);
  // gt.level_order_line_wise(gt.root);
  // gt.level_order_line_wise_zig_zag(gt.root);
  // gt.level_order_line_wise(gt.root);
  // gt.mirror(gt.root);
  // cout << "after";
  // gt.level_order_line_wise_using_count(gt.root);
  // gt.remove_leaves(gt.root);
  // gt.linearize(gt.root);
  // gt.level_order_line_wise(gt.root);
  // cout << gt.find(gt.root, 100);
  // for (int path : gt.nodeToRootPath(gt.root, 99))
  // {
  //     cout << path << " ";
  // }
  // for (auto outer : gt.nodeToRootPathMultiple(gt.root, 50))
  // {
  //     for (auto val : outer)
  //     {
  //         cout << val << " ";
  //     }
  //     cout << endl;
  // }
  return 0;
}
