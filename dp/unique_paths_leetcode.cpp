#include <vector>
using namespace std;
class Solution {
public:
  //* fucking slow recursive code
  //* memo code
  //   int uniquePathsMemo(int sr, int sc, int dr, int dc,
  //                       std::vector<std::vector<int>> &dp) {

  //     if (sc > dc or sr > dr) {
  //       return 0;
  //     }

  //     if (sr == dr and sc == dc) {
  //       return 1;
  //     }

  //     if (dp[sr][sc]) {
  //       return dp[sr][sc];
  //     }

  //     int fromRight = uniquePathsMemo(sr, sc + 1, dr, dc, dp);
  //     int fromDown = uniquePathsMemo(sr + 1, sc, dr, dc, dp);

  //     int myAns = fromRight + fromDown;
  //     dp[sr][sc] = myAns;

  //     return myAns;

  //*we could use memoisation because you could reach sr,sc from 2 paths one
  // from left and one from top,but the unique paths from sr,sc to sr,dc remain
  // same
  //   }

  int uniquePathsTab(int m, int n) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[m][n] = 1;

    for (int i = dp.size() - 1; i >= 0; i--) {
      for (int j = dp[0].size() - 1; j >= 0; j--) {

        if (i == dp.size() - 1 and j == dp[0].size() - 1) {

          dp[i][j] = 1;
        } else if (i + 1 == dp.size()) {
          dp[i][j] = dp[i][j + 1];
        } else if (j + 1 == dp[0].size()) {
          dp[i][j] = dp[i + 1][j];
        } else {
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
      }
    }

    return dp[0][0];
  }

  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    return uniquePathsTab(m - 1, n - 1);
  }
};