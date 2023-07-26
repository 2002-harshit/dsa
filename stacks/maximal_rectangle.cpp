#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getLargestArea(vector<int> vec) {

  int maxArea = 0;
  stack<int> indices;
  indices.push(-1);

  for (int i = 0; i <= vec.size(); i++) {

    int val = (i == vec.size()) ? 0 : vec[i];
    while (!(indices.top() == -1) and vec[indices.top()] >= val) {
      int rightMin = i;
      int height = vec[indices.top()];
      indices.pop();
      int leftMin = indices.top();
      maxArea = max(maxArea, height * (rightMin - leftMin - 1));
    }

    indices.push(i);
  }

  return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix) {

  vector<int> height(matrix[0].size());
  for (int i = 0; i < height.size(); i++) {
    height[i] = matrix[0][i] - '0';
  }

  int area = getLargestArea(height);

  for (int i = 1; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == '1') {
        height[j]++;
      } else {
        height[j] = 0;
      }
    }

    area = max(area, getLargestArea(height));
  }

  return area;
}
