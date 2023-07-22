#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNgetr(vector<int> arr) {
  vector<int> ans(arr.size());
  ans[ans.size() - 1] = -1;
  stack<int> idx;
  idx.push(arr.size() - 1);

  for (int i = arr.size() - 2; i >= 0; i--) {

    while (!idx.empty() and arr[i] >= arr[idx.top()]) {

      idx.pop();
    }

    if (!idx.empty())
      ans[i] = arr[idx.top()];
    else
      ans[i] = -1;
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