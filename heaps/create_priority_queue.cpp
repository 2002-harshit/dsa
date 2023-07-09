//* lets create our own heap and priority queue
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//* this is a min heap
class PriorityQueue {
  vector<int> *vec;

public:
  PriorityQueue() { vec = new vector<int>(); }
  PriorityQueue(vector<int> &arr) {
    // vec = new vector<int>();

    // for (int &val : arr) {
    //   this->add(val);
    // }
    //* the above piece of code takes nlogn time, beacuse jo ki last level wale
    //*items hai they all have to be upheapified in the worst case, so in a
    //*perfect binary tree , last level has n/2 nodes, which have to be
    //*upheafied *h height which is log(n), so (n/2)logn, this happens because
    //*we do the *costly operation(upheapify) for the worst memmbers that are at
    //* lowest *level, because they have to be upheapified h height

    //* lets try O(n) ctr;
    vec = new vector<int>;
    for (int &val : arr) {
      vec->push_back(val);
    }

    //* now lets honour heap order priority
    for (int i = (arr.size() - 1) / 2; i >= 0; --i) {

      downHeapify(i);
    }
  }
  void upheapify(int index) {
    if (index == 0) {
      return;
    }
    int parentIdx = (index - 1) / 2;
    if (vec->at(index) < vec->at(parentIdx)) {
      swap(vec->at(index), vec->at(parentIdx));
      upheapify(parentIdx);
    }
  }
  void add(int num) {

    // vec->push_back(num);
    // int childIdx = vec->size() - 1;
    // int parentIdx = (childIdx - 1) / 2;

    // while (childIdx != 0 and vec->at(childIdx) < vec->at(parentIdx))
    // {
    //     swap(vec->at(childIdx), vec->at(parentIdx));
    //     childIdx = parentIdx;
    //     parentIdx = (childIdx - 1) / 2;
    // }
    //* the above is the iterative approach

    //*lets look at recursive
    vec->push_back(num);
    upheapify(vec->size() - 1);
  }
  void downHeapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int minIndex = index; //* finding the minimum
    if (left < vec->size() and vec->at(left) < vec->at(index)) {
      minIndex = left;
    }
    if (right < vec->size() and vec->at(right) < vec->at(index)) {
      minIndex = right;
    }

    //* now we have the minimum;
    if (index != minIndex) {
      swap(vec->at(index), vec->at(minIndex));
      downHeapify(minIndex);
    }
  }
  int remove() {
    if (vec->size() == 0) {
      cout << "Underflow";
      return -1;
    }

    //* swap with last element becuase if we delete vec[0], that is itself o(n)
    // becuase whole vector will shift towards left;
    int min = vec->at(0);
    swap(vec->at(0), vec->at(vec->size() - 1));
    vec->erase(vec->begin() + vec->size() - 1);
    downHeapify(0);
    return min;
  }

  int peek() {
    if (vec->size() == 0) {
      cout << "Underflow";
      return -1;
    }

    return vec->at(0);
  }
  int size() { return vec->size(); }
  void print() {
    for (int &val : (*vec)) {
      cout << val << " ";
    }
  }
};

int main() {
  //   PriorityQueue pq;
  //   pq.add(1);
  //   pq.add(2);
  //   pq.add(3);
  //   pq.add(6);
  //   pq.add(5);
  //   pq.add(10);
  //   pq.add(7);
  //   pq.add(4);
  //   pq.print();
  //   cout << pq.remove();
  //   cout << pq.remove();
  //   cout << pq.remove();
  vector<int> vec = {3, 4, 1, 2, 10, 0, 19};
  PriorityQueue pq(vec);
  pq.print();
  return 0;
}