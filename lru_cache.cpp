#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  int key;
  int value;
  Node *prev = nullptr;
  Node *next = nullptr;
  Node(int k, int val) : key(k), value(val) {}
};

class LRUCache {
public:
  int cap = 0;
  unordered_map<int, Node *> cache;
  Node *head = nullptr; //* these are dummy nodes to save from null pointers,
  Node *tail = nullptr; //*otherwise lengthy code;

  LRUCache(int capacity) {

    cap = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {

    if (cache.count(key)) {
      removeNode(cache[key]);
      insertBeginning(cache[key]);
      return cache[key]->value;
    }

    return -1;
  }

  void put(int key, int value) {

    if (cache.count(key)) {
      //* element exists
      cache[key]->value = value;
      removeNode(cache[key]);
      insertBeginning(cache[key]);

    } else {
      //* element does not exist
      Node *new_node = new Node(key, value);
      if (cache.size() == cap) {

        Node *deleted = removeNode(tail->prev);
        cache.erase(deleted->key);
        delete deleted;

        insertBeginning(new_node);

      } else {
        insertBeginning(new_node);
      }
      cache[key] = new_node;
    }
  }

  void insertBeginning(Node *new_node) {
    new_node->next = head->next;
    head->next = new_node;
    new_node->prev = head;
    new_node->next->prev = new_node;
  }

  Node *removeNode(Node *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = nullptr;
    node->prev = nullptr;
    return node; //* returns the deleted node
  }
};
