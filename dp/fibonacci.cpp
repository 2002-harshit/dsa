#include <bits/stdc++.h>
#include <vector>
using namespace std;

int fibMemoized(int n, vector<int> &answers) {

  if (n == 0 or n == 1) {
    return n;
  }

  if (answers[n] != 0) {
    return answers[n];
  }

  int fibn = fibMemoized(n - 1, answers) + fibMemoized(n - 2, answers);
  answers[n] = fibn;
  return fibn;
}

int main() {
  vector<int> answers(11);
  cout << fibMemoized(10, answers);
  return 0;
}