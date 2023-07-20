#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

// vector<int> findTargetSumSubset(vector<int> &vec, int idx, int currSum,
//                                 vector<int> &currVec, int target) {

//   if (idx == vec.size()) {
//     if (currSum == target) {
//       return currVec;
//     } else {
//       return {};
//     }
//   }

//   vector<int> nahiLiya =
//       findTargetSumSubset(vec, idx + 1, currSum, currVec, target);

//   if (nahiLiya.size() != 0) {
//     return nahiLiya;
//   }

//   currVec.push_back(vec[idx]);
//   vector<int> liya =
//       findTargetSumSubset(vec, idx + 1, currSum + vec[idx], currVec, target);

//   currVec.pop_back();
//   if (liya.size() != 0) {
//     return liya;
//   }

//   return {};
// }

// int main() {
//   vector<int> vec = {4, 2, 7, 1, 3};
//   vector<int> currVec;
//   int target = 4;
//   for (int &val : findTargetSumSubset(vec, 0, 0, currVec, target)) {
//     cout << val << " ";
//   }
//   return 0;
// }

//* using tabulation

// #include <bits/stdc++.h>
// #include <iterator>
// #include <vector>
// using namespace std;

// bool targetSumSubsetTabulation(vector<int> vec, int target) {

//   vector<vector<bool>> dp(vec.size() + 1, vector<bool>(target + 1));

//   //* some base cases
//   dp[0][0] = true;
//   for (int j = 1; j < target + 1; j++) {
//     dp[0][j] = false;
//   }
//   for (int i = 1; i < vec.size() + 1; i++) {
//     dp[i][0] = true;
//   }

//   for (int i = 1; i < vec.size() + 1; i++) {
//     for (int j = 1; j < target + 1; j++) {
//       if (j < vec[i - 1]) {
//         dp[i][j] = dp[i - 1][j];
//       } else {

//         dp[i][j] = dp[i - 1][j] || dp[i - 1][j - vec[i - 1]];
//       }
//     }
//   }

//   //   for (vector<bool> &vec : dp) {
//   //     for (bool val : vec) {
//   //       cout << val << " ";
//   //     }
//   //     cout << endl;
//   //   }

//   return dp[dp.size() - 1][dp[0].size() - 1];
// }

// int main() {
//   vector<int> vec = {4, 2, 7, 1, 3};
//   int target = 10;
//   cout << targetSumSubsetTabulation(vec, target);
//   return 0;
// }