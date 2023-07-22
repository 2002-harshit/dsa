#include <bits/stdc++.h>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void generate_parantheses(int n, int open, int close, string currAns,
                          vector<string> &ans) {

  if (open == n and close == n) {
    ans.push_back(currAns);
    return;
  }

  //*opening
  if (open != n) {
    currAns.push_back('(');
    generate_parantheses(n, open + 1, close, currAns, ans);
    currAns.pop_back();
  }

  if (open > close) {
    currAns.push_back(')');
    generate_parantheses(n, open, close + 1, currAns, ans);
    currAns.pop_back();
    //* this is the important condition, you can only put an closing bracket
    //*when you have more opening brackets
  }
}

int main() {

  vector<string> ans;
  generate_parantheses(3, 0, 0, "", ans);
  for (string &par : ans) {
    cout << par << endl;
  }
}