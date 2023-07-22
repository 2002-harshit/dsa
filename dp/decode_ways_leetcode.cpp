#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

//* you can calculate the number of ways of to decode, byh first decoding by all
//*ways, and then finding the size of the result, but thijs leads to exploring
//*all ways, so this will give TLE.

//* we will solve it using DP now

int numWaysToDecode(string number) {

  vector<int> dp(number.size());

  if (number[0] == '0') {
    return 0;
  }

  //* storage and meaning, at ith index we store the number of ways to decode
  //*[0,i];
  dp[0] = 1;

  //* now travel and solve
  for (int i = 1; i < number.size(); i++) {
    char ch1 = number[i - 1];
    char ch2 = number[i];

    if (ch1 == '0' and ch2 == '0') {

      dp[i] = 0;

    } else if (ch1 == '0' and ch2 != '0') {

      dp[i] = dp[i - 1];

    } else if (ch1 != '0' and ch2 == '0') {

      if ((ch1 - '0') <= 2) {

        dp[i] = (i <= 1 ? 1 : dp[i - 2]);

      } else {

        dp[i] = 0;
      }
    } else {

      dp[i] = dp[i - 1];
      if (stoi(string(1, ch1) + string(1, ch2)) <= 26) {
        dp[i] += (i <= 1 ? 1 : dp[i - 2]);
      }
    }

    // cout << dp[i] << endl;
  }

  return dp[dp.size() - 1];
}

int main() {
  cout << numWaysToDecode("21123");
  return 0;
}