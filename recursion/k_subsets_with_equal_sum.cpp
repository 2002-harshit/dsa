#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

//* this is an extension of partition in k non empty subsets, you only change
//*the base case, and maintain the sum of partitons(subsetSum) for easier base
//*case.
//* again classic levels and options, you cxan either jooin a team or form you
//*own team

void solution(int idx, vector<int> &arr, int k, vector<int> &subsetSum,
              vector<vector<int>> &ans) {

  if (idx == arr.size()) {
    int eachSum = subsetSum[0];
    for (int &s : subsetSum) {
      if (eachSum != s) {
        return;
      }
    }

    for (vector<int> &parts : ans) {
      for (int &val : parts) {
        cout << val;
      }
      cout << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < ans.size(); i++) {
    if (!ans[i].empty()) {
      ans[i].push_back(arr[idx]);
      subsetSum[i] += arr[idx];
      solution(idx + 1, arr, k, subsetSum, ans);
      subsetSum[i] -= arr[idx];
      ans[i].pop_back();
      //* i undo my steps, kyunki backtrack karna hai
    } else {

      ans[i].push_back(arr[idx]);
      subsetSum[i] += arr[idx];
      solution(idx + 1, arr, k, subsetSum, ans);
      subsetSum[i] -= arr[idx];
      ans[i].pop_back();
      break;
    }
  }
}

int main() {

  int n = 6;
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int sum = accumulate(arr.begin(), arr.end(), 0);
  int k = 3;

  if (k == 1) {
    for (int &val : arr) {
      cout << val << ",";
    }
    return 0;
  }

  if (k > n or sum % k != 0) {
    return -1;
  }

  vector<vector<int>> ans(k);
  vector<int> subsetSum(k); //* this will story sum of each subset in the
                            //*answer, for easy *comparison in the base case

  solution(0, arr, k, subsetSum, ans);

  return 0;
}