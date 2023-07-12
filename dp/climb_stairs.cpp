#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getPathsNumMemo(int n, vector<int> &answers) {

  if (n == 0) {
    return 1;
  }

  if (n < 0) {
    return 0;
  }

  if (answers[n] != 0) {
    return answers[n];
  }

  int pathsm1 = getPathsNumMemo(n - 1, answers);
  int pathsm2 = getPathsNumMemo(n - 2, answers);
  int pathsm3 = getPathsNumMemo(n - 3, answers);

  answers[n] = pathsm1 + pathsm2 + pathsm3;
  return pathsm1 + pathsm2 + pathsm3;
}

int getPathsNumTab(int n) {
  vector<int> dp(n + 1);

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {

    if (i == 1) {
      dp[i] = dp[i - 1];
    } else if (i == 2) {
      dp[i] = dp[i - 1] + dp[i - 2];
    } else {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
  }

  return dp[n];
}

int main() {

  vector<int> answers(5);
  //   cout << getPathsNumMemo(4, answers);
  cout << getPathsNumTab(4);

  return 0;
}