#include <bits/stdc++.h>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

void reverseStack(stack<int> &st, vector<int> &vec, int i) {
  if (st.empty()) {
    return;
  }

  vec.push_back(st.top());
  st.pop();
  reverseStack(st, vec, i - 1);
  st.push(vec[i]);
}

int main() {

  stack<int> st;
  st.push(41);
  st.push(3);
  st.push(32);
  st.push(2);
  st.push(11);
  vector<int> vec;

  reverseStack(st, vec, st.size() - 1);

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}