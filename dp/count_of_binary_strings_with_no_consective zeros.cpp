#include <bits/stdc++.h>
using namespace std;

int countBinaryStrings(int n) {

  if (n == 0) {
    return 0;
  }
  int appropriateStringsEndingWith0Len1 = 1;  //* previous state
  int appropriateStringsEndingWith1Len1 = 1;  //* previous state
  int appropriateStringsEndingWith0Plus1 = 0; //* next state
  int appropriateStringsEndingWith1Plus1 = 0; //* next state

  for (int i = 1; i < n; i++) {

    appropriateStringsEndingWith0Plus1 = appropriateStringsEndingWith1Len1;
    appropriateStringsEndingWith1Plus1 =
        appropriateStringsEndingWith1Len1 + appropriateStringsEndingWith0Len1;

    appropriateStringsEndingWith0Len1 = appropriateStringsEndingWith0Plus1;
    appropriateStringsEndingWith1Len1 = appropriateStringsEndingWith1Plus1;
  }

  return appropriateStringsEndingWith0Len1 + appropriateStringsEndingWith1Len1;
}

int main() {
  cout << countBinaryStrings(5);
  return 0;
}