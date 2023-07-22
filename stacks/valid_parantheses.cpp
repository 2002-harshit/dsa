#include <asm-generic/errno.h>
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

  stack<char> st;
  for (char &ch : s) {
    if (ch == '{' or ch == '(' or ch == '[') {

      st.push(ch);
    } else {
      if (ch == ')') {
        if (st.top() == '{' or st.top() == '[')
          return false;

        if (st.empty())
          return false;

        st.pop();
      } else if (ch == '}') {
        if (st.top() == '(' or st.top() == '[')
          return false;

        if (st.empty())
          return false;

        st.pop();
      } else if (ch == ']') {
        if (st.top() == '{' or st.top() == '(')
          return false;

        if (st.empty())
          return false;

        st.pop();
      }
    }
  }

  if (!st.empty()) {
    return false;
  }

  return true;
}

int main() {
  string s = "({([])}())";
  return 0;
}