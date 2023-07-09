//* lets create our own hashmap
//* hashmap only guarangtess an average case time complexity of o(lambda)
//* if by chance all the keys have same hash, they will end up in same
//* bucket,the complexity will be O(n);
#include "bits/stdc++.h"
#include <algorithm>
#include <forward_list>
#include <string>
#include <vector>
using namespace std;

template <typename K, typename V> class HashMapNode {
public:
  K key;
  V value;

  HashMapNode(K key, V value) : key(key), value(value) {}
};

template <typename K, typename V> class HashMap {
  int size; //* n

  vector<forward_list<HashMapNode<K, V>>>
      buckets; //* forward list is singly linked list in cpp

public:
  HashMap() {
    initbuckets(4);
    size = 0; //* this is the size of hashmap
  }
  void initbuckets(int N) {
    //* N is the size of bucket array, n/N is the load factor(lambda), or the
    // average nodes per bucket, and the time complexity of operations is
    // O(lambda), constant
    buckets = vector<forward_list<HashMapNode<K, V>>>(N);
  }

  void put(K key, V value) {
    int bucketIndex = hashFn(key);
    // int nodeIndex = findWithinBucket(key, bucketIndex);

    // if (nodeIndex != -1)
    // {
    //     for (HashMapNode<K, V> &node : buckets[bucketIndex])
    //     {
    //     }
    // }
    for (HashMapNode<K, V> &node : buckets[bucketIndex]) {
      if (node.key == key) {
        node.value = value;
        return;
      }
    }
    //* means element is not present , so insert in end
    //* here i has to write typename because iterator data type is dependent on
    // K,V , so typename is required;
    typename forward_list<HashMapNode<K, V>>::iterator beforeEnd =
        buckets[bucketIndex].before_begin();

    for (auto it = buckets[bucketIndex].begin();
         it != buckets[bucketIndex].end(); ++it) {
      ++beforeEnd;
    }

    HashMapNode<K, V> newNode(key, value);
    // buckets[bucketIndex].insert_after(beforeEnd, newNode);
    buckets[bucketIndex].insert_after(beforeEnd, newNode);
    this->size++;

    //* now lets tackle rehashing
    double lambda = size * 1.0 / buckets.size();
    if (lambda > 2.0) {
      rehash();
    }
  }

  void rehash() {

    vector<forward_list<HashMapNode<K, V>>> oldBuckets = buckets;
    initbuckets(2 * oldBuckets.size());
    this->size = 0;

    for (forward_list<HashMapNode<K, V>> &l : oldBuckets) {

      for (HashMapNode<K, V> &node : l) {

        this->put(node.key, node.value);
      }
    }

    oldBuckets.clear();
  }

  bool containsKey(K key) {
    int bucketIndex = hashFn(key);
    for (HashMapNode<K, V> &node : buckets[bucketIndex]) {
      if (node.key == key) {
        return true;
      }
    }

    return false;
  }

  V get(K key) {
    int bucketIndex = hashFn(key);
    for (HashMapNode<K, V> &node : buckets[bucketIndex]) {
      if (node.key == key) {
        return node.value;
      }
    }

    throw out_of_range("Key does not exist");
  }

  V remove(K key) {
    int bucketIndex = hashFn(key);
    if (buckets[bucketIndex].empty()) {
      throw out_of_range("Key does not exist");
    }
    V removed;

    auto beforNode = buckets[bucketIndex].before_begin();

    for (auto it = buckets[bucketIndex].begin();
         it != buckets[bucketIndex].end(); ++it) {
      if (it->key == key) {
        removed = it->value;
        break;
      }
      beforNode++;
    }

    if (beforNode == buckets[bucketIndex].end()) {
      throw out_of_range("Key does not exist");
    } else {
      buckets[bucketIndex].erase_after(beforNode);
    }

    return removed;
  }

  int hashFn(K key) {
    hash<K>
        hasher; //* here K cannot be custom types, otherwise i have to
                // define the custom hash function, so not like java hashcode
    //* hasher(key) returns size_t
    int idx = static_cast<int>(hasher(key)) % buckets.size();
    cout << "Bucket index for " << key << " is " << idx << endl;

    return static_cast<int>(hasher(key)) % buckets.size();
  }

  //* get the keys set
  vector<K> keyset() {

    vector<K> keyset;

    for (forward_list<HashMapNode<K, V>> &l : buckets) {

      for (HashMapNode<K, V> &node : l) {
        keyset.push_back(node.key);
      }
    }

    return keyset;
  }

  int getSize() { return this->size; }
  void print() {
    for (int i = 0; i < buckets.size(); i++) {
      cout << "list " << i << "\n\n";
      for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it) {
        cout << it->key << " " << it->value << endl;
      }
      cout << endl;
    }
  }
};

int main() {
  HashMap<string, int> h1;
  try {

    h1.put("harshit", 1);
    h1.put("peeya", 1);
    h1.put("garv", 1);
    h1.put("gaurav", 1);
    h1.put("roshan", 1);
    h1.put("ritu", 1);
    h1.put("rohi", 1);
    h1.put("ri", 1);
    h1.put("r", 1);
    h1.put("a", 1);
    h1.put("b", 1);
    // h1.put("peeya", 10);
    h1.print();

    // h1.remove("harshit");
    // h1.print();
    // h1.remove("harshit");
    // cout << h1.remove("peeya");
    // h1.put("ritu", 0);
    // h1.print();
    // vector<string> keys = h1.keyset();
    // for_each(keys.begin(), keys.end(), [](string &k) { k = "h"; });//* this
    // actually chnages the value
    // for_each(keys.begin(), keys.end(), [](string k) { cout << k << " "; });
    cout << h1.getSize();

  } catch (exception &e) {
    cout << e.what();
  }
  return 0;
}