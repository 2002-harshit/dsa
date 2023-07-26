#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <stack>
#include <vector>
using namespace std;

int getLargestOne(vector<int> &heights) {
  int maxArea = 0;

  stack<int> st;
  vector<int> nsetlIdx(heights.size());
  nsetlIdx[0] = -1;
  st.push(0);

  for (int i = 1; i < heights.size(); i++) {
    while (!st.empty() and heights[st.top()] >= heights[i]) {
      st.pop();
    }

    if (st.empty()) {
      nsetlIdx[i] = -1;
    } else {
      nsetlIdx[i] = st.top();
    }

    st.push(i);
  }

  //   for (int &val : nsetlIdx)
  //     cout << val << " ";
  //   cout << endl;

  /////////////////////////////////////////////

  stack<int> st1;
  vector<int> nsetrIdx(heights.size(), -1);
  st1.push(0);

  for (int i = 1; i < heights.size(); i++) {

    while (!st1.empty() and heights[st1.top()] > heights[i]) {
      int topIdx = st1.top();
      st1.pop();
      nsetrIdx[topIdx] = i;
    }

    st1.push(i);
  }

  //   for (int &val : nsetrIdx)
  //     cout << val << " ";
  //   cout << endl;

  for (int i = 0; i < heights.size(); i++) {

    int width;

    if (nsetlIdx[i] != -1 and nsetrIdx[i] != -1) {

      width = (nsetrIdx[i] - nsetlIdx[i] - 1);

    } else if (nsetlIdx[i] == -1 and nsetrIdx[i] != -1) {

      width = (nsetrIdx[i]);

    } else if (nsetlIdx[i] != -1 and nsetrIdx[i] == -1) {

      width = (heights.size() - nsetlIdx[i] - 1);

    } else {

      width = heights.size();
    }

    maxArea = max(maxArea, heights[i] * width);
  }

  return maxArea;
}

int main() {
  vector<int> vec = {2, 1, 5, 6, 2, 3};
  cout << getLargestOne(vec);
}