#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solution(int i, int n, int k, vector<vector<int>> ans) {
  // write your code here

  //* this is the base case
  if (i == n + 1) {
    for (vector<int> &each : ans) {
      if (each.empty()) {
        return;
      }
    }

    for (vector<int> &each : ans) {
      for (int &val : each) {
        cout << val;
      }
      cout << " ";
    }
    cout << endl;
    return;
  }

  /*
   * the code is pretty easy, remember the levels and options approach, each
   * level is a number, and the choices are ya toh pehle se hi kisi already
   * formed team mein aa jaao, ya khud ki ek team bana lo*/

  for (vector<int> &each : ans) {
    if (!each.empty()) {
      each.push_back(i);
      solution(i + 1, n, k, ans);
      each.pop_back();
    } else {
      each.push_back(i);
      solution(i + 1, n, k, ans);
      each.pop_back();
      break; //* this break is important to stop the formation of different
             //*permuatations
    }
  }
}

int main() {

  int n = 4;
  int k = 0;
  vector<vector<int>> ans(k);
  solution(1, n, k, ans);

  return 0;
}