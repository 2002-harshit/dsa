#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

void solution(int n, int i, vector<bool> &used, string currAns) {

  if (i == n + 1) {
    cout << currAns << endl;
    return;
  }

  if (used[i]) {
    solution(n, i + 1, used, currAns);
  } else {

    used[i] = true;
    solution(n, i + 1, used, currAns + "(" + to_string(i) + ") ");

    for (int opt = i + 1; opt <= n; opt++) {

      if (!used[opt]) {

        used[opt] = true;
        solution(n, i + 1, used,
                 currAns + "(" + to_string(i) + "," + to_string(opt) + ") ");
        used[opt] = false;
      }
    }

    used[i] = false;
  }
}

int main() {
  vector<bool> used(4, false);
  solution(3, 1, used, "");
  return 0;
}