#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int tribonacciTab(int n) {
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    int i = 0;
    while (true) {
      dp[i + 3] = dp[i] + dp[i + 1] + dp[i + 2];
      if (i + 3 == n) {
        break;
      }
    }

    return dp[dp.size() - 1];
  }

  int tribonacci(int n) { return tribonacciTab(n); }
};