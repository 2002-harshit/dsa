#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

// void smallestNumberOfCoins(vector<int> coins, int idx, int currSum,
//                            vector<int> &currVec, int target, int &maxCount,
//                            int currCount) {

//   if (currSum > target or idx == coins.size()) {
//     return;
//   }

//   if (currSum == target) {
//     maxCount = min(maxCount, currCount);
//     return;
//   }

//   currVec.push_back(coins[idx]);
//   smallestNumberOfCoins(coins, idx, currSum + coins[idx], currVec, target,
//                         maxCount, currCount + 1);
//   currVec.pop_back();

//   smallestNumberOfCoins(coins, idx + 1, currSum, currVec, target, maxCount,
//                         currCount);
// }

int smallestNumberOfCoinsTab(vector<int> coins, int target) {
  vector<int> dp(target + 1, -1);

  //* storage and meaning, dp[i] will store the minimum number of coins to pay
  //*i amount;
  dp[0] = 0;
  for (int &coin : coins) {
    for (int j = coin; j < dp.size(); j++) {
      if (dp[j - coin] != -1 and dp[j] != -1) {
        dp[j] = min(1 + dp[j - coin], dp[j]);
      } else if (dp[j - coin] != -1 and dp[j] == -1) {
        dp[j] = 1 + dp[j - coin];
      }
    }
  }

  return dp[dp.size() - 1];
}

int main() {

  vector<int> coins = {1, 2, 5};
  vector<int> currVec;
  int ans = INT_MAX;
  //   smallestNumberOfCoins(coins, 0, 0, currVec, 11, ans, 0);
  cout << ans;

  return 0;
}