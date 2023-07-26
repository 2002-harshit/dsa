#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {

    vector<int> ans;
    unordered_map<int, int> um;
    stack<int> st;
    st.push(nums2[nums2.size() - 1]);
    um[nums2[nums2.size() - 1]] = -1;

    for (int i = nums2.size() - 2; i >= 0; i--) {

      while (!st.empty() and st.top() <= nums2[i]) {
        st.pop();
      }

      if (st.empty()) {
        um[nums2[i]] = -1;
      } else {
        um[nums2[i]] = st.top();
      }

      st.push(nums2[i]);
    }

    for (int &val : nums1) {
      ans.push_back(um[val]);
    }

    return ans;
  }
};

int main() { return 0; }