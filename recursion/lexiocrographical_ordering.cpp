#include <bits/stdc++.h>
using namespace std;

void print_lexicographical(int num, int max)
{
    if (num > max)
    {
        return;
    }
    cout << num << endl;
    for (int i = 0; i <= 9; i++)
    {
        print_lexicographical(10 * num + i, max);
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        print_lexicographical(i, 500);
    }
    return 0;
}