#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int climbWithMinMoves(int n, vector<int> &arr) {
  //* we will be using tabulation for this

  //* storage and meaning
  vector<int> dp(n + 1, -1);
  //* every ith cell indicates the minimum moves from i to n;

  //* smallest problem minmoves from 10 to 10 that is 0;
  dp[n] = 0;

  //* now move from right to left
  for (int i = n - 1; i >= 0; i--) {

    if (arr[i] >= 1) {
      int min_moves = INT_MAX;
      //* means if you can move
      for (int j = 1; j <= arr[i]; j++) {
        if (i + j < dp.size() and dp[i + j] != -1) {
          min_moves = min(dp[i + j], min_moves);
        }
      }

      if (min_moves != INT_MAX)
        dp[i] = 1 + min_moves;
    }
  }

  return dp[0];
}

int main() {

  int n = 10;
  vector<int> steps = {3, 2, 4, 2, 0, 2, 3, 1, 2, 2};
  cout << climbWithMinMoves(n, steps);

  return 0;
}