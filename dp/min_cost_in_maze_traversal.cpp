#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int getMinCostMazeTraversal(int r, int c, vector<vector<int>> &maze) {

  //* classic expectation faith apporach

  if (r == maze.size() - 1 and c == maze[0].size() - 1) {
    return maze[r][c];
  }

  if (r == maze.size() or c == maze[0].size()) {
    //* bc bahar aa gaya
    return INT_MAX;
  }

  int minCostRightSe = getMinCostMazeTraversal(r, c + 1, maze);
  int minCostNicheSe = getMinCostMazeTraversal(r + 1, c, maze);

  return maze[r][c] + min(minCostRightSe, minCostNicheSe);

  //* this code has redundant function calls
  /*
   * assume a 6x6 matrix, and we know we can reach a cell , by two ways that is
   * right and down calls.
   * lets assume you reached (3,3) with a right call, now when you backtract and
   * reach there with a down call also, the min cost from (3,3) to (6,6) still
   * remains same, but calculation happens again, so lets memoize
   */
}

int getMinCostMazeTraversalMemo(int r, int c, vector<vector<int>> &maze,
                                vector<vector<int>> &dp) {

  if (r == maze.size() - 1 and c == maze[0].size() - 1) {
    return maze[r][c];
  }

  if (r == maze.size() or c == maze[0].size()) {
    //* bc bahar aa gaya
    return INT_MAX;
  }

  if (dp[r][c] != -1) {
    return dp[r][c];
  }

  cout << "At "
       << "( " << r << "," << c << " )" << endl;
  int minCostRightSe = getMinCostMazeTraversalMemo(r, c + 1, maze, dp);
  int minCostNicheSe = getMinCostMazeTraversalMemo(r + 1, c, maze, dp);

  int ans = maze[r][c] + min(minCostRightSe, minCostNicheSe);
  dp[r][c] = ans;

  return ans;
}

int getMinCostMazeTraversalTab(vector<vector<int>> &maze) {
  //* ok declare storage and assign meaning

  vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), -1));
  //* each ith cell will store min cost sum to destination, also notice the size
  //*of dp array is not always up by 1

  //* base case;
  //* from dest to dest
  int r = maze.size();
  int c = maze[0].size();
  //   dp[r - 1][c - 1] = maze[r - 1][c - 1];

  //* now lets solve the problem backward
  for (int i = r - 1; i >= 0; i--) {
    for (int j = c - 1; j >= 0; j--) {
      if (i == r - 1 and j == c - 1) {
        dp[i][j] = maze[i][j]; //* this is the base case
      } else {

        int min_cost = INT_MAX;
        if (i + 1 < r) {
          min_cost = min(min_cost, dp[i + 1][j]);
        }

        if (j + 1 < c) {
          min_cost = min(min_cost, dp[i][j + 1]);
        }

        dp[i][j] = maze[i][j] + min_cost;
      }
    }
  }

  return dp[0][0];
}

int main() {
  int n = 6;
  int m = 6;
  vector<vector<int>> maze = {{0, 1, 4, 2, 8, 2}, {4, 3, 6, 5, 0, 4},
                              {1, 2, 4, 1, 4, 6}, {2, 0, 7, 3, 2, 2},
                              {3, 1, 5, 9, 2, 4}, {2, 7, 0, 8, 5, 1}};

  vector<vector<int>> dp(maze.size() + 1, vector<int>(maze[0].size() + 1, -1));
  //   cout << getMinCostMazeTraversalMemo(0, 0, maze, dp);

  cout << getMinCostMazeTraversalTab(maze);
}
