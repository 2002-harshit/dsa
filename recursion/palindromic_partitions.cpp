#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void makePalindromicParitions(string ques, vector<string> currAns,
                                vector<vector<string>> &ans) {

    if (ques.empty()) {
      ans.push_back(currAns);
      return;
    }

    for (int i = 1; i <= ques.size(); i++) {
      string substr = ques.substr(0, i);
      string reversed = substr;
      reverse(reversed.begin(), reversed.end());
      if (substr == reversed) {
        currAns.push_back(substr);
        makePalindromicParitions(ques.substr(i), currAns, ans);
        currAns.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> currAns;
    makePalindromicParitions("abaab", currAns, ans);
    return ans;
  }
};

int main() { return 0; }