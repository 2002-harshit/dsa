#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> ph = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

void solvePhoneBacktrack(string digits, int idx, string currAns, vector<string> &ans)
{
    if (idx == digits.size())
    {
        ans.push_back(currAns);
        return;
    }
    for (int i = 0; i < ph[digits[idx] - '0'].size(); i++)
    {
        //* this is the backtrackign stuff, you explore all the options, its like levels and options
        currAns.push_back(ph[digits[idx] - '0'][i]);
        solvePhoneBacktrack(digits, idx + 1, currAns, ans);
        currAns.pop_back();
    }
}

int main()
{

    vector<string> ans;
    string currAns = "";
    string digits = "23";
    solvePhoneBacktrack(digits, 0, currAns, ans);
    return 0;
}