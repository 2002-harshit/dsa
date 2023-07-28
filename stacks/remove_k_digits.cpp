#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {

    stack<char> st;
    string ans;

    for (int i = 0; i < num.size(); i++) {

      while (k > 0 and !st.empty() and st.top() > num[i]) {
        st.pop();
        k--;
      }
      st.push(num[i]);
    }

    while (k > 0 and !st.empty()) {
      st.pop();
      k--;
    }

    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;
    while (i < ans.size() and ans[i] == '0')
      i++;

    return (ans.substr(i).size() == 0) ? "0" : ans.substr(i);
  }
};
