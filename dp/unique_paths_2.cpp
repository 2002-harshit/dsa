#include <bits/stdc++.h>
#include <vector>
using namespace std;

//* again lets fucking do this with tabulation

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

    //* obstacle is 1, and empty space is 0
    vector<vector<int>> dp(obstacleGrid.size(),
                           vector<int>(obstacleGrid[0].size(), 0));
    //* define storage and meaning, meaning i,j stores the number of ways from
    //*i,j to the bottom right
    if (obstacleGrid[dp.size() - 1][obstacleGrid[0].size() - 1] == 1) {
      return 0;
    }

    // dp[dp.size() - 1][dp[0].size() - 1] = 1;

    for (int i = dp.size() - 1; i >= 0; i--) {
      for (int j = dp[0].size() - 1; j >= 0; j--) {
        if (i == dp.size() - 1 and j == dp[0].size() - 1) {
          dp[i][j] = 1;
        } else {

          if (!obstacleGrid[i][j]) {
            if (i + 1 == dp.size()) {
              dp[i][j] = dp[i][j + 1];
            } else if (j + 1 == dp[0].size()) {
              dp[i][j] = dp[i + 1][j];
            } else {
              dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
          }
        }
      }
    }

    return dp[0][0];
  }
};