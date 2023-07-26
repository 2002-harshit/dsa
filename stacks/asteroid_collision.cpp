// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;
    st.push(asteroids[0]);
    vector<int> ans;

    for (int i = 1; i < asteroids.size(); i++) {
      if (st.empty() or
          (!st.empty() and !(st.top() > 0 and asteroids[i] < 0))) {
        st.push(asteroids[i]);
      } else {

        //* yahan toh pop banta hai
        while (!st.empty() and st.top() > 0 and asteroids[i] < 0 and
               abs(st.top()) < abs(asteroids[i])) {
          st.pop();
        }
        if (st.empty()) {
          st.push(asteroids[i]);
        } else if (!st.empty() and st.top() > 0 and asteroids[i] < 0 and
                   abs(st.top()) == abs(asteroids[i])) {
          st.pop();
        } else if (!st.empty() and st.top() < 0) {
          st.push(asteroids[i]);
        }
      }
    }

    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
//* finally done

int main() {

  vector<int> asteroids = {10, 2, -5};
  (new Solution())->asteroidCollision(asteroids);
  return 0;
}