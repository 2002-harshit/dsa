#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

int getLargestArea(vector<int> vec) {

  int maxArea = 0;
  stack<int> indices;
  indices.push(-1); //* acts as a left min

  for (int i = 0; i <= vec.size(); i++) {

    int val = (i == vec.size()) ? 0 : vec[i];
    while (!(indices.top() == -1) and vec[indices.top()] >= val) {
      //* agar main inhe pop kara paa raha hoon, toh inka right min mein khud
      //*hoon
      int rightMin = i;
      int height = vec[indices.top()];
      indices.pop();
      int leftMin = indices.top();
      //* aur yeh humesha hoga ki mujhe pop karke jo mera niche
      //* wala elemnt hoga woh mera left min hoga, kyum=nki jab
      //* main aaya tha toh maine apne se bade pop kara diye the,
      //* toh definitely mujhse neeche mere se chota element hai
      maxArea = max(maxArea, height * (rightMin - leftMin - 1));
    }

    indices.push(i);
  }

  return maxArea;
}

int main() {
  getLargestArea({6, 2, 5, 4, 5, 1, 6});
  return 0;
}