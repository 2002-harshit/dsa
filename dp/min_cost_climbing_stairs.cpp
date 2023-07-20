#include <bits/stdc++.h>
using namespace std;

//* classic dp problem
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {

    vector<int> dp(cost.size() + 1);
    dp[dp.size() - 1] = 0;

    for (int i = dp.size() - 2; i >= 0; i--) {

      int min_route = INT_MAX;
      if (i + 2 > dp.size() - 1) {
        dp[i] = cost[i];
      } else {
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
      }
    }

    return min(dp[0], dp[1]);
  }
};