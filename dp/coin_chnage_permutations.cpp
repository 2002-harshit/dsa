#include <bits/stdc++.h>
#include <vector>
using namespace std;

//* these are permutations

int waysToPayTargetUsingVecTabulation(vector<int> &vec, int target) {
  vector<int> dp(target + 1);

  dp[0] = 1;

  for (int i = 1; i < dp.size(); i++) {
    for (int coin = 0; coin < vec.size(); coin++) {
      if (i >= vec[coin]) {
        dp[i] = dp[i] + dp[i - vec[coin]];
      }
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