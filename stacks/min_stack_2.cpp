#include <iostream>
#include <stack>
using namespace std;

//* now we wont use any extra space for min_val
class MinStack {
public:
  stack<long int> st;
  long int min_val = 0;
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.push(val);
      min_val = val;
    } else {

      if (val >= min_val) {
        st.push(val);
      } else {
        //* val<min, this is strictly less
        //* now the incoming value is lesser than the minimum value
        //* so we store a marker, a farzi value in our stack, in order to know
        //*ki bhai idhar min badla hai
        st.push(val + (val - min_val));
        min_val = val;
      }
    }
  }

  void pop() {

    if (st.top() < min_val) {

      int top = st.top();
      min_val = 2 * min_val - top;
      st.pop();

    } else {
      st.pop();
    }
  }

  int top() {

    if (st.top() < min_val) {
      return min_val;
    } else {
      return st.top();
    }
  }

  int getMin() { return min_val; }
};