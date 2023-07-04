#include <bits/stdc++.h>
using namespace std;

string alphas = "abcdefghijklmnopqrstuvwxyz";

void print_encodings(string encoded, string decoded)
{
    if (encoded == "")
    {
        cout << decoded << endl;
        return;
    }
    for (int i = 1; i <= encoded.size(); i++)
    {
        int val = stoi(encoded.substr(0, i));
        if (val > 26)
        {
            break;
        }
        print_encodings(encoded.substr(i), decoded + alphas[val - 1]);
    }
}

int main()
{
    print_encodings("655196", "");
    return 0;
}