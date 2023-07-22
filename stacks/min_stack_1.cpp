
#include <iostream>
#include <stack>
using namespace std;

//* here we were using fucking extra space,a new stack for maintaining the
//* minimum values

class MinStack {
public:
  stack<int> st;
  stack<int> min_st;
  MinStack() {}

  void push(int val) {
    st.push(val);
    if (min_st.empty())
      min_st.push(val);
    else if (val < min_st.top()) {
      min_st.push(val);
    }
  }

  void pop() {
    int top = st.top();
    st.pop();

    if (top == min_st.top()) {
      min_st.pop();
    }
  }

  int top() { return st.top(); }

  int getMin() { return min_st.top(); }
};

int main() { return 0; }