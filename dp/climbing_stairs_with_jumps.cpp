#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getStaisNumTab(int n, vector<int> &arr) {
  vector<int> dp(n + 1);
  dp[n] = 1; //* number of ways from n to n

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= arr[i]; ++j) {

      if (i + j < dp.size()) {
        dp[i] += dp[i + j];
      }
    }
  }

  return dp[0];
}

int main() {

  int n = 10;
  vector<int> arr = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
  cout << getStaisNumTab(n, arr);
  return 0;
}