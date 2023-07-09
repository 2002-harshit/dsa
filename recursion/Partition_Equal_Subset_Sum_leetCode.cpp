#include <bits/stdc++.h>
#include <vector>
using namespace std;

//* this throws TLe, optimisation is DP

class Solution {
public:
  bool getPartitions(int idx, vector<int> &nums, vector<int> &partitionSum,
                     vector<vector<int>> &ans) {

    if (idx == nums.size()) {
      for (vector<int> &part : ans) {
        if (part.empty()) {
          return false;
        }
      }

      int eachPartSum = partitionSum[0];
      for (int i = 1; i < partitionSum.size(); i++) {
        if (eachPartSum != partitionSum[i]) {
          return false;
        }
      }

      return true;
    }

    for (int i = 0; i < ans.size(); i++) {

      if (!ans.empty()) {

        ans[i].push_back(nums[idx]);
        partitionSum[i] += nums[idx];
        if (getPartitions(idx + 1, nums, partitionSum, ans)) {
          return true;
        }
        ans[i].pop_back();
        partitionSum[i] -= nums[idx];

      } else {

        ans[i].push_back(nums[idx]);
        partitionSum[i] += nums[idx];
        if (getPartitions(idx + 1, nums, partitionSum, ans)) {
          return true;
        }
        ans[i].pop_back();
        partitionSum[i] -= nums[idx];
        break; //* imp inorder to avoid permutations
      }
    }

    return false;
  }

  bool canPartition(vector<int> &nums) {
    vector<vector<int>> ans(2);
    vector<int> partitionSum(2);

    return getPartitions(0, nums, partitionSum, ans);
  }
};