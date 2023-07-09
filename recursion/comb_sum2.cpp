#include <bits/stdc++.h>
using namespace std;

//* here the set can contain duplicate nummbers also, so may end up with same
//combinations, you have to prevent it, i guess this will be same as subset 2
//problem

class Solution {
public:
  void makeCombos2(vector<int> &arr, int index, int target, int currSum,
                   vector<int> &currCombo, vector<vector<int>> &allCombos) {
    if (currSum == target) {
      allCombos.push_back(currCombo);
      return;
      //* this base case should be at the top because index==arr.size() can also
      //happen when your currSum is equal to target, it juts means you have
      //finished the array, with either greater sum or equal sum
    }
    if (currSum > target or index == arr.size()) {
      return;
    }

    //* first lets take
    currCombo.push_back(arr[index]);
    makeCombos2(arr, index + 1, target, currSum, currCombo, allCombos);
    currCombo.pop_back();

    //* now lets skip all the copies of arr[i];
    while (index + 1 < arr.size() and arr[index + 1] == arr[index]) {
      index++;
    }

    //* this is the not take call, or the not included call
    makeCombos2(arr, index + 1, target, currSum, currCombo, allCombos);
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> currCombo;
    vector<vector<int>> allCombos;

    sort(candidates.begin(), candidates.end(), less_equal<int>());

    makeCombos2(candidates, 0, target, 0, currCombo, allCombos);
    return allCombos;
  }
};

int main() { return 0; }