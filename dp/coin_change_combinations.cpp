#include <bits/stdc++.h>
#include <vector>
using namespace std;

int waysToPayTargetUsingVecTabulation(vector<int> &vec, int target) {
  vector<int> dp(target + 1);

  //* assign the meaning, every cell stored what arfe the number of ways to pay
  //*that cell amount using given coins
  dp[0] = 1;

  for (int coin = 0; coin < vec.size(); coin++) {
    for (int i = vec[coin]; i < dp.size(); i++) {
      dp[i] = dp[i] + dp[i - vec[coin]];
    }
  }

  return dp[dp.size() - 1];
}

int main() {

  vector<int> vec = {2, 3, 5};
  int target = 10;
  cout << waysToPayTargetUsingVecTabulation(vec, target);
  return 0;
}