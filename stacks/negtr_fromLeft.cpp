#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNgetr(vector<int> arr) {
  vector<int> ans(arr.size(), -1);
  stack<int> idx;
  idx.push(0);

  for (int i = 1; i < arr.size(); i++) {
    while (!idx.empty() and arr[i] > arr[idx.top()]) {

      int top_idx = idx.top();
      ans[top_idx] = arr[i];
      idx.pop();
    }

    idx.push(i);
  }

  return ans;
}

int main() {

  for (int val : findNgetr({5, 6, 10, 9, 8, 10})) {
    cout << val << " ";
  }

  return 0;
}