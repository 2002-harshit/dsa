#include <bits/stdc++.h>
#include <chrono>
#include <vector>
using namespace std;

class Solution {
public:
  int betterApp(vector<int> &height) {
    int water = 0;

    vector<int> leftMax(height.size());
    vector<int> rightMax(height.size());
    leftMax[0] = height[0];
    rightMax[rightMax.size() - 1] = height[height.size() - 1];

    for (int i = 1; i < leftMax.size(); i++) {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    for (int i = rightMax.size() - 2; i >= 0; i--) {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < leftMax.size(); i++) {
      water += min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
  }
  int trap(vector<int> &height) { return betterApp(height); }
};

int main() {}