#include <bits/stdc++.h>
using namespace std;

void print_permutations(string ques, string permut)
{
    if (ques == "")
    {
        cout << permut << endl;
        return;
    }
    for (int i = 0; i < ques.size(); i++)
    {
        print_permutations(ques.substr(0, i) + ques.substr(i + 1), permut + ques[i]);
    }
}

int main()
{
    print_permutations("abc", "");
    return 0;
}