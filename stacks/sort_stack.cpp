#include <algorithm>
#include <bits/stdc++.h>
#include <regex>
#include <stack>
using namespace std;

void insert(stack<int> &, int);

void sort(stack<int> &st) {

  if (st.empty()) {
    return;
  }

  int top = st.top();
  st.pop();
  sort(st);

  insert(st, top);
}

void insert(stack<int> &st, int val) {

  if (st.empty()) {
    st.push(val);
    return;
  }

  if (st.top() > val) {
    int top = st.top();
    st.pop();
    insert(st, val);
    st.push(top);
  } else {
    st.push(val);
    return;
  }
}

int main() {
  stack<int> st;
  st.push(41);
  st.push(3);
  st.push(32);
  st.push(2);
  st.push(11);

  sort(st);

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}