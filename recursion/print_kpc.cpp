#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> letters = {{0, ".;"},
                                      {1, "abc"},
                                      {2, "def"},
                                      {3, "ghi"},
                                      {4, "jkl"},
                                      {5, "mno"},
                                      {6, "pqrs"},
                                      {7, "tu"},
                                      {8, "vwx"},
                                      {9, "yz"}};

void print_kpc(string code, string ans)
{
    if (code == "")
    {
        cout << ans << endl;
        return;
    }
    char digit = code[0];
    string roq = code.substr(1);

    for (int i = 0; i < letters[digit - '0'].size(); i++)
    {
        print_kpc(roq, ans + letters[digit - '0'][i]);
    }
}

int main()
{
    print_kpc("78", "");
    return 0;
}