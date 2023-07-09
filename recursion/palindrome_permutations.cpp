#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <utility>
using namespace std;

//* mind you these are permutations and therefore you have to take all the chars

void generatepw(int currPos, int totalLen, unordered_map<char, int> &freq,
                char &oddChar, string currAns) {

  if (currPos == totalLen) {
    string orig = currAns;
    reverse(orig.begin(), orig.end());
    if (oddChar != '\0') {
      cout << currAns + oddChar + orig << endl;
    } else {
      cout << currAns + orig << endl;
    }
    // cout << currAns;

    return;
  }

  for (auto &[key, value] : freq) {

    if (value > 0) {
      value--;
      generatepw(currPos + 1, totalLen, freq, oddChar, currAns + key);
      value++;
    }
    // freq[key]++;//* this line is problematic , beacause i am adding keys
    //* also beacuse earlier i was erasing the entry when value became 0, and my
    //*base case was empty map,which *might cause issue with the loop
  }
}

int main() {

  string ques = "abbaababc";
  unordered_map<char, int> freq;
  for (char &ch : ques) {
    freq[ch]++;
  }

  //   bool moreOneThanOdd = false;
  //   for (pair<const char, int> &p : freq) {
  //   }
  //   for (auto &[k, v] : freq) {
  //     v = 0;
  //     //* this is by ref, so values change
  //   }

  //   for (pair<const char, int> &p : freq) {
  //     cout << p.second << endl;
  //   }
  int oddCount = 0;
  char oddCountChar = '\0';
  int newLen = 0;
  //* mind you the below loop is by reference
  for (auto &[key, value] : freq) {

    if (value & 1) {
      oddCount++;
      oddCountChar = key;
    }
    value = value / 2;
    newLen += (value);
  }

  if (oddCount > 1) {
    cout
        << "Not possible, pallindromes only exist when at max 1 odd count value"
        << endl;
  } else {

    // cout << newLen;
    // for (auto &[key, val] : freq)
    //   cout << key << " " << val << endl;
    generatepw(0, newLen, freq, oddCountChar, "");
  }

  return 0;
}